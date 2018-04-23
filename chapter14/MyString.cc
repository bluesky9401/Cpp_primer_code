#include "MyString.h"
#include <memory>
#include <iostream>
using std::cout;
using std::endl;

std::ostream &operator<<(std::ostream &os, const MyString &rhs)
{
    for(auto curr_ptr = rhs.first_; curr_ptr != rhs.last_; ++curr_ptr) {
        cout << (*curr_ptr);
    }
    cout << endl;
} 
std::pair<char*, char*> MyString::allocate_n_copy(const char *beg, const char *end)
{
    auto newdata = alloc_.allocate(end - beg);
    return {newdata, std::uninitialized_copy(beg, end, newdata)};
}

void MyString::free()
{
    for(auto curr_ptr = first_; curr_ptr != last_; ++curr_ptr){
        alloc_.destroy(curr_ptr);
    }
    alloc_.deallocate(first_, size());
}
