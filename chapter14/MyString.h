#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <memory>
#include <utility>
#include <iostream>

class MyString {
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs); 
public:
    // 构造函数
    MyString(): MyString("") { }
    MyString(const MyString &obj);
    MyString(const char *const_ptr);

    // 拷贝赋值运算符
    MyString& operator=(const MyString & rhs);
    // 返回size以及指向MyString元素的指针
    size_t size() { return last_ - first_;}
    char *poiterChar() { return first_;}
    // 析构函数
    ~MyString();
private:
    std::pair<char*, char*> allocate_n_copy(const char *beg, const char *end);
    void free();    
private:
    char *first_;
    char *last_;
    std::allocator<char> alloc_;
};


std::ostream &operator<<(std::ostream &os, const MyString &rhs); 

inline MyString::MyString(const MyString &obj)
{
    auto ptr_pair = allocate_n_copy(obj.first_, obj.last_);
    first_ = ptr_pair.first;
    last_ = ptr_pair.second;
}

inline MyString::MyString(const char *const_ptr)
{
    char *ptr = const_cast<char*>(const_ptr);
    while (*ptr) {
        ++ptr;
    }
    auto ptr_pair = allocate_n_copy(const_ptr, ptr);
    first_ = ptr_pair.first;
    last_ = ptr_pair.second;
}

MyString& MyString::operator=(const MyString &rhs)
{
    auto ptr_pair = allocate_n_copy(rhs.first_, rhs.last_);
    first_ = ptr_pair.first;
    last_ = ptr_pair.second;
}

inline MyString::~MyString() { free(); }
#endif
