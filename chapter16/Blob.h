#ifndef _BLOB_H_
#define _BLOB_H_
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>

template <typename> class BlobPtr;
template <typename> class Blob; // the forward declaration provide the operand ==

template <typename T>
    bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
  
    // constructor function
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It> Blob(It b, It e); 
    // return the size of Blob
    size_type size() const { return ptr_data_->size(); }
    bool empty() const { return ptr_data_->empty(); }
  
    // add elements and remove elements
    void push_back(const T &element);// copy version
    void push_back(T &&element); // move version
    void pop_back();

    // reach the element
    T& back();
    T& operator[](size_type i); 

private:
    std::shared_ptr<std::vector<T>> ptr_data_; 
    void check(size_type i, const std::string &msg) const;
};

/** the definition of friend function operand== **/
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    auto size = lhs.size();
    for (std::size_t i = 0; i != size(); ++i) {
        if (lhs[i] != rhs[i])
                return false;
    }
    return true;
}

/** contructor function **/
template <typename T>
Blob<T>::Blob(): ptr_data_(std::make_shared<std::vector<T>>()) { }
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): ptr_data_(std::make_shared<std::vector<T>>(il)) { }
template <typename T>
template <typename It> 
Blob<T>::Blob(It b, It e):ptr_data_(std::make_shared<std::vector<T>>(b, e)) { }

/** add elements(copy version) **/
template <typename T>
void Blob<T>::push_back(const T &element)
{
    ptr_data_->push_back(element);
}

/** add elements(move version) **/
template <typename T>
void Blob<T>::push_back(T &&element)
{
    ptr_data_->push_back(std::move(element));
}

/** remove element **/
template <typename T>
void Blob<T>::pop_back()
{
    check(0, "the container is empty, can't pop element!");
    ptr_data_->pop_back();
}

/** reach the final element **/
template <typename T>
T& Blob<T>::back()
{
    check(0, "the container is empty, can't return the final element!");
    return ptr_data_->back();
}

/** return the responding element **/
template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*ptr_data_)[i];
}

/** check whether access out of range **/
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= ptr_data_->size()) {
        throw std::out_of_range(msg);
    }
}

/**
 * the definition of BlobPtr template
 * BlobPtr is used for manage the elements in Bolb container, just like iterator
 */
template <typename T> class BlobPtr {
public:
    // constructor function
    BlobPtr(): curr_(0) { }
    BlobPtr(const Blob<T> &obj, std::size_t curr):
            wptr_(obj.ptr_data_), curr_(curr) { } 

    // access the element 
    T& operator*() const
    { 
        auto p = check(curr_, "dereference pase end!");
        return (*p)[curr_];  
    }

    // access specify element(non_const version)
    T& operator[](std::size_t i)
    { 
        auto ptr = check(i, "access out of range!");
        return (*ptr)[i];
    }

    // access specify element(const version)
    const T& operator[](std::size_t i) const
    { 
        auto ptr = check(i, "access out of range!");
        return (*ptr)[i];// because it's const member function, so this pointer is
                         // a const pointer point to const object,
                         // so in order to avoid edit the object, return const T& rather than T&
    }

    // increment and decrement
    BlobPtr& operator++();// prefix
    BlobPtr& operator++(int);// postfix
    BlobPtr& operator--();// prefix
    BlobPtr& operator--(int);// postfix

private:
    std::shared_ptr<std::vector<T>> check(std::size_t pos, const std::string &err_info) const;
    std::weak_ptr<std::vector<T>> wptr_; // wptr_ point to the first element of Blob
    std::size_t curr_; // curr_ save the current position
};

/** the increment operand(prefix) **/
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr_ + 1, "increment pass the end!");
    ++curr_;
    return *this;
}

/** the decrement operand(postfix) **/
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this; // return the origin object
    ++*this;
    return ret;
}

/** the decrement operand(prefix) **/
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    check(curr_-1, "decrement pass the begin!");
    --curr_;
    return *this;    
}

/** the decrement operand(postfix) **/
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

/** if pos out of range, throw out_of_range exception
 *  else return a shared_ptr
 */
template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t pos, const std::string &err_info) const
{
    auto ret = wptr_.lock();// check whether wptr_ bind Blob
    if (!ret)
        throw std::runtime_error("unbound BlobPtr!");
    if (pos >= ret->size() || pos < 0 )
        throw std::out_of_range(err_info);
    return ret;
}
#endif
