#ifndef _VEC_H_
#define _VEC_H_
#include <memory>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iostream>

template <typename T> class Vec;// forward declaration

/** the declaration of friend function **/
template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs);

template <typename T> class Vec {
    friend bool operator==<T>(const Vec<T> &lhs, const Vec<T> &rhs);
    friend bool operator!=<T>(const Vec<T> &lhs, const Vec<T> &rhs);
public:
    // constructor function
    Vec(): element_(nullptr), first_free_(nullptr), cap_(nullptr) { }
    Vec(const std::initializer_list<T> initList);
    // copy constructor function
    Vec(const Vec&);
    // copy assign function
    Vec& operator=(const Vec&);
    // move constructor function
    Vec(Vec&&) noexcept;
    // move copy assignment function
    Vec& operator=(Vec&&) noexcept;
    // destructor function
    ~Vec();
    
    // 添加删除元素
    void push_back(const T&);
    void pop_back();
    
    // 返回容器存放元素数量
    std::size_t size() const { return first_free_ - element_; }
    // 返回在不重新分配内存空间的情况下，容器最多能容纳多少个元素
    std::size_t capacity() const { return cap_ - element_; }
    // 改变容器存放元素的数量
    void resize(std::size_t n);
    void resize(std::size_t n, const T &elem);

    T* begin() const { return element_; } 
    T* end() const { return first_free_; }
    // 分配至少能容纳n个元素的空间
    void reserve(std::size_t n);

private:
    static std::allocator<T> alloc_;// 分配空间的类
    // 检查元素空间是否消耗完毕,若消耗完毕则重新分配内存空间
    void check_n_alloc()
    {
        if(size() == capacity()){
            reallocate();
        }
    }
    std::pair<T*, T*> alloc_n_copy
            (const T*, const T*);// 拷贝赋值需要分配独立内存
    void free();// 销毁元素并且释放内存(此操作应该由对象自动完成，为避免用户误用，设置为private)
    void reallocate();// 重新分配对象的内存
    T *element_;// 指向数组首元素的指针
    T *first_free_;// 指向尾后第一个空闲元素的指针
    T *cap_;// 指向数组尾后位置的指针
};

template <typename T> std::allocator<T> Vec<T>::alloc_;

/** 拷贝构造函数 **/
template <typename T>
Vec<T>::Vec(const Vec& obj)
{
    auto pair_new_data = alloc_n_copy(obj.begin(), obj.end());
    element_ = pair_new_data.first;
    first_free_ = cap_ = pair_new_data.second;
}

/** 初始化器为initializer_list形式 **/
template <typename T>
Vec<T>::Vec(const std::initializer_list<T> initList)
{
    auto pair_ptr = alloc_n_copy(initList.begin(), initList.end());
    element_ = pair_ptr.first;
    first_free_ = cap_ = pair_ptr.second; 
}

/** 拷贝赋值运算符 **/
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
    // 分配与rhs中元素占用空间一样大小的空间
    auto pair_ptr_new_data = alloc_n_copy(rhs.begin(), rhs.end());
    // 释放旧内存空间
    free();
    // 更新指针
    element_ = pair_ptr_new_data.first;
    first_free_ = cap_ = pair_ptr_new_data.second;
}

/** 移动构造函数 **/
template <typename T>
Vec<T>::Vec(Vec&& obj) noexcept : 
                      element_(obj.element_), first_free_(obj.first_free_), cap_(obj.cap_)
{
    obj.element_ = obj.first_free_ = obj.cap_ = nullptr;     
}

/** 移动赋值函数 **/
template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& rhs) noexcept
{   
    if(this != &rhs) {
        free();// 注意将lhs所绑定的内存释放，否则会造成内存泄漏
        // 资源权限转移
        element_ = rhs.element_;
        first_free_ = rhs.first_free_;
        cap_ = rhs.cap_;
        // 将移后源对象的指针置为空指针
        rhs.element_ = rhs.first_free_ = rhs.cap_ = nullptr;     
    }
    return *this;
}
/** 重载相等运算符与不等运算符 **/
template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
    size_t size = lhs.size();
    size_t count = 0;
    for(auto lhs_ptr = lhs.element_, rhs_ptr = rhs.element_; 
                    count != size; count++, ++lhs_ptr, ++rhs_ptr) {
        if (*lhs_ptr != *rhs_ptr) {
            return false;
        }
    }
    return true;
}
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs == rhs);
}

/** 析构函数 **/
template <typename T>
Vec<T>::~Vec()
{
    free();
}

/** 插入元素到尾后 **/
template <typename T>
void Vec<T>::push_back(const T &elem)
{
    check_n_alloc();
    // 在first_free指向的元素中构造str的副本，并且递增first_free指针
    alloc_.construct(first_free_++, elem);
}

/** 删除尾后元素 **/
template <typename T>
void Vec<T>::pop_back()
{
   alloc_.destroy(--first_free_); 
}

/** 改变容器存放元素的数量 **/
template <typename T>
void Vec<T>::resize(std::size_t n)
{
    resize(n, T());
}
template <typename T>
void Vec<T>::resize(size_t n, const T &elem)
{
    reserve(n);
    if(n > size()){
        for(size_t count = size(); count != n; ++count){
            push_back(elem);
        }
    }else{
        for(size_t count = size(); count != n; --count){
            pop_back();
        }
    }
}

/** 拷贝赋值需要分配独立内存 **/
template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *beg, const T *end)
{
    auto ptr_alloc = alloc_.allocate(end - beg);
    return {ptr_alloc, std::uninitialized_copy(beg, end, ptr_alloc)};
}

/** 销毁元素并且释放内存(此操作应该由对象自动完成，为避免用户误用，设置为private) **/
template <typename T>
void Vec<T>::free()
{   
    // 首先判断element_是否为空
    if(element_) {
        // allocate类所分配的内存在释放之前要先destroy对象,注意str采用引用形式
        std::for_each(element_, first_free_, [this] (T &elem) ->void { alloc_.destroy(&elem);});
        alloc_.deallocate(element_, cap_ - element_);
    }
}

/** 重新分配对象内存 **/
template <typename T>
void Vec<T>::reallocate()
{
    // 分配当前大小两倍的内存空间
    auto new_capacity = size()? size()*2 : 1;
    auto ptr_new_data = alloc_.allocate(new_capacity);
    // 将数据从旧内存转移到新内存
    std::cout << "the origin addr: " << (void*) element_ << std::endl;
    std::cout << "the allocate addr: " << (void*) ptr_new_data << std::endl;
    auto ptr_dest = ptr_new_data;
    auto ptr_src  = element_;
    for(size_t i = 0; i != size(); i++)
        alloc_.construct(ptr_dest++, std::move(*ptr_src++));
    free(); // 一旦移动完元素就释放旧内存(此处注意移后源对象中的指针被置为nullptr，即释放其不会影响移前所绑定的资源)
    // 更新指针
    element_ = ptr_new_data;
    first_free_ = ptr_dest;
    cap_ = element_ + new_capacity;
    std::cout << "the current addr: " << (void*) element_ << std::endl;
}

/** 分配至少能容纳n个元素的空间 **/
template <typename T>
void Vec<T>::reserve(std::size_t n)
{
    if(n > capacity()){
        auto ptr_new_data = alloc_.allocate(n);
        auto ptr_dest = ptr_new_data;
        auto ptr_src = element_;
        for(size_t i = 0; i != size(); i++){
            alloc_.construct(ptr_dest++, std::move(*ptr_src++));
        }
        free();
        element_ = ptr_new_data;
        first_free_ = ptr_dest;
        cap_ = ptr_new_data + n;
    }
}
#endif
