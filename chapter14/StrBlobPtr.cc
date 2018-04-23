#include <vector>
#include <string>
#include <stdexcept>
#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>>  
     StrBlobPtr::check(std::size_t index, const std::string &msg) const
{
    auto ret = wptr_.lock();
    if(!ret)    
        throw std::runtime_error("unbound StrBlobPtr");
    if(index >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr_, "dereference past end");
    return (*p)[curr_];
}
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

