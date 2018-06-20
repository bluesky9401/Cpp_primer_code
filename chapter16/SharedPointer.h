#ifndef _SHAREDPOINTER_H
#define _SHAREDPOINTER_H
#include <functional>

template <typename T> class SharedPointer;
template <typename T>
void swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs)
{
    using std::swap;
    swap(lhs.ptr_obj_, rhs.ptr_obj_);
    swap(lhs.ptr_use_count_, rhs.ptr_use_count_);
    swap(lhs.deleter_, rhs.deleter_);
}

template <typename T> class SharedPointer {
    friend void swap<T>(SharedPointer &lhs, SharedPointer &rhs);
public:
    // constructor function
    SharedPointer(): ptr_obj_(nullptr), 
                     ptr_use_count_(new std::size_t), 
                     deleter_([](T* ptr) { delete ptr; }) { }
    SharedPointer(SharedPointer &obj): ptr_obj_(obj.ptr_obj_),
                                       ptr_use_count_(obj.ptr_use_count_),
                                       deleter_(obj.deleter_) { ++*ptr_use_count_; }
    explicit SharedPointer(T *ptr): ptr_obj_(ptr),
                                    ptr_use_count_(new std::size_t(1)),
                                    deleter_([](T* ptr) { delete ptr; }) { }
    SharedPointer(T *ptr, std::function<void (T*)> deleter): ptr_obj_(ptr),
                                                             ptr_use_count_(new std::size_t(1)),
                                                             deleter_(deleter) { }
    SharedPointer(SharedPointer &obj, std::function<void (T*)> deleter): ptr_obj_(obj.ptr_obj_),
                                                                         ptr_use_count_(obj.ptr_use_count_),
                                                                         deleter_(deleter) { }
    // copy assignment function
    SharedPointer& operator=(SharedPointer &rhs)
    {
        ++*rhs.ptr_use_count_;
        decrement_destroy();
        ptr_obj_ = rhs.ptr_obj_;
        ptr_use_count_ = rhs.ptr_use_count_;
        deleter_ = rhs.deleter_;
    }

    // dereference the SharedPointer
    T& operator*() { return *ptr_obj_; }
    const T& operator*() const { return *ptr_obj_; }
    
    // swap the two SharedPointer
    SharedPointer& swap(SharedPointer &rhs) 
    {
        using std::swap;
        swap(*this, rhs);
        return *this;
    }
    
    // return the object pointer
    T* get() { return ptr_obj_; }

    // check whether only this SharedPointer point to the object
    bool unique() { return *ptr_use_count_ == 1 ? true : false; }
    std::size_t use_count() { return *ptr_use_count_; }
    
    void reset() { decrement_destroy(); }
    void reset(T* q) 
    { 
        decrement_destroy(); 
        ptr_obj_ = q;
        deleter_ = [](T* ptr) { delete ptr; };
    }
    void reset(T* q, std::function<void (T*)> deleter)
    {
        decrement_destroy();
        ptr_obj_ = q;
        deleter_ = deleter;
    }

    ~SharedPointer() { decrement_destroy(); }
private:
    void decrement_destroy()
    {
        --*ptr_use_count_;
        if (ptr_obj_ && 0 == *ptr_use_count_) {
            delete ptr_use_count_;
            deleter_(ptr_obj_);
        } else if(!ptr_obj_)
            delete ptr_use_count_;
        ptr_obj_ = nullptr; 
        ptr_use_count_ = nullptr;
    }
    T *ptr_obj_;
    std::size_t *ptr_use_count_;
    std::function<void (T*)> deleter_;
};
#endif
