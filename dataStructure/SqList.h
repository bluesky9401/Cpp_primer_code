#ifndef _SQLIST_H_
#define _SQLIST_H_

template <typename T, unsigned MaxSize>
class SqList {
public:
    SqList():length_(0) { }
    void push_back(T& element);
    bool empty() { return length_ == 0 ? 1:0; }
    void insert(T &element, unsigned i);
private:
    T data_[MaxSize];
    unsigned length_;
};

template <typename T, unsigned MaxSize>
void SqList<T, MaxSize>::push_back(T &element)
{
    data_[length_] = element;
    ++length_;
}

template <typename T, unsigned MaxSize>
void SqList<T, MaxSize>::insert(T &element, unsigned i)
{}
#endif
