#ifndef _STRVEC_H_
#define _STRVEC_H_
#include <string>
#include <memory>
#include <initializer_list>
#include <utility>

class StrVec{
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
public:
    //构造函数
    StrVec(): element_(nullptr), first_free_(nullptr), cap_(nullptr) { }
    StrVec(const std::initializer_list<std::string> initList_str);
    // 拷贝构造函数
    StrVec(const StrVec&);
    // 拷贝赋值运算符
    StrVec& operator=(const StrVec&);
    // 移动构造函数
    StrVec(StrVec&&) noexcept;
    // 移动赋值函数
    StrVec& operator=(StrVec&&) noexcept;
    // emplace函数
    template <typename... Args> void emplace_back(Args&&...);
    // 析构函数
    ~StrVec();

    // 添加删除元素
    void push_back(const std::string&);
    void pop_back();

    // 返回容器存放元素数量
    size_t size() const { return first_free_ - element_; }
    // 返回在不重新分配内存空间的情况下，容器最多能容纳多少个元素
    size_t capacity() const { return cap_ - element_; }
    // 改变容器存放元素的数量
    void resize(size_t n);
    void resize(size_t n, const std::string str);

    std::string* begin() const { return element_; } 
    std::string* end() const { return first_free_; }
    // 分配至少能容纳n个元素的空间
    void reserve(size_t n);
private:
    static std::allocator<std::string> alloc_;// 分配空间的类
    // 检查元素空间是否消耗完毕,若消耗完毕则重新分配内存空间
    void check_n_alloc()
    {
        if(size() == capacity()){
            reallocate();
        }
    }
    std::pair<std::string*, std::string*> alloc_n_copy
            (const std::string*, const std::string*);// 拷贝赋值需要分配独立内存
    void free();// 销毁元素并且释放内存(此操作应该由对象自动完成，为避免用户误用，设置为private)
    void reallocate();// 重新分配对象的内存
    std::string *element_;// 指向数组首元素的指针
    std::string *first_free_;// 指向尾后第一个空闲元素的指针
    std::string *cap_;// 指向数组尾后位置的指针
};
// 友元函数声明
bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
template <typename... Args> 
inline void StrVec::emplace_back(Args&&... args)
{
    check_n_alloc();
    alloc_.construct(first_free_++, std::forward<Args>(args)...);
}
#endif
