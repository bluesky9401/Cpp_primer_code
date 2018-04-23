#include "StrVec.h"
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

using std::string;
std::allocator<std::string> StrVec::alloc_;// 定义分配内存空间的类

/** 拷贝构造函数 **/
StrVec::StrVec(const StrVec& obj)
{
    auto pair_new_data = alloc_n_copy(obj.begin(), obj.end());
    element_ = pair_new_data.first;
    first_free_ = cap_ = pair_new_data.second;
}

/** 初始化器为initializer_list形式 **/
StrVec::StrVec(const std::initializer_list<std::string> initList_str)
{
    auto pair_ptr = alloc_n_copy(initList_str.begin(), initList_str.end());
    element_ = pair_ptr.first;
    first_free_ = cap_ = pair_ptr.second; 
}

/** 拷贝赋值运算符 **/
StrVec& StrVec::operator=(const StrVec &rhs)
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
StrVec::StrVec(StrVec&& obj) noexcept : 
                      element_(obj.element_), first_free_(obj.first_free_), cap_(obj.cap_)
{
    obj.element_ = obj.first_free_ = obj.cap_ = nullptr;     
}

/** 移动赋值函数 **/
StrVec& StrVec::operator=(StrVec&& rhs) noexcept
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

/** 析构函数 **/
StrVec::~StrVec()
{
    free();
}

/** 插入元素到尾后 **/
void StrVec::push_back(const std::string &str)
{
    check_n_alloc();
    // 在first_free指向的元素中构造str的副本，并且递增first_free指针
    alloc_.construct(first_free_++, str);
}

/** 删除尾后元素 **/
void StrVec::pop_back()
{
   alloc_.destroy(--first_free_); 
}

/** 改变容器存放元素的数量 **/
void StrVec::resize(size_t n)
{
    resize(n, std::string());
}

void StrVec::resize(size_t n, const std::string str)
{
    reserve(n);
    if(n > size()){
        for(size_t count = size(); count != n; ++count){
            push_back(str);
        }
    }else{
        for(size_t count = size(); count != n; --count){
            pop_back();
        }
    }
}

/** 拷贝赋值需要分配独立内存 **/
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *beg, const std::string *end)
{
    auto ptr_alloc = alloc_.allocate(end - beg);
    return {ptr_alloc, uninitialized_copy(beg, end, ptr_alloc)};
}

/** 销毁元素并且释放内存(此操作应该由对象自动完成，为避免用户误用，设置为private) **/
void StrVec::free()
{   
    // 首先判断element_是否为空
    if(element_) {
        // allocate类所分配的内存在释放之前要先destroy对象,注意str采用引用形式
        std::for_each(element_, first_free_, [this] (string &str) ->void { alloc_.destroy(&str);});
        alloc_.deallocate(element_, cap_ - element_);
    }
}

/** 重新分配对象内存 **/
void StrVec::reallocate()
{
    // 分配当前大小两倍的内存空间
    auto new_capacity = size()? size()*2 : 1;
    auto ptr_new_data = alloc_.allocate(new_capacity);
    // 将数据从旧内存转移到新内存
    cout << "the origin addr: " << (void*) element_ << endl;
    cout << "the allocate addr: " << (void*) ptr_new_data << endl;
    auto ptr_dest = ptr_new_data;
    auto ptr_src  = element_;
    for(size_t i = 0; i != size(); i++)
        alloc_.construct(ptr_dest++, std::move(*ptr_src++));
    free(); // 一旦移动完元素就释放旧内存(此处注意移后源对象中的指针被置为nullptr，即释放其不会影响移前所绑定的资源)
    // 更新指针
    element_ = ptr_new_data;
    first_free_ = ptr_dest;
    cap_ = element_ + new_capacity;
    cout << "the current addr: " << (void*) element_ << endl;
}

/** 分配至少能容纳n个元素的空间 **/
void StrVec::reserve(size_t n)
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
