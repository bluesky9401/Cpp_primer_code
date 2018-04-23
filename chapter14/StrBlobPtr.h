#ifndef _STRBLOBPTR_H_
#define _STRBLOBPTR_H_

#include <vector>
#include <memory>
#include <string>
#include "StrBlob.h"
class StrBlobPtr {
public:
    //构造函数
    StrBlobPtr() : curr_(0) { }
    StrBlobPtr(StrBlob &obj, size_t sz = 0):
            wptr_(obj.data), curr_(sz) { }
    // 解引用操作与前缀递增操作
    std::string& deref() const;
    StrBlobPtr& incr();
    bool operator!=(const StrBlobPtr& rhs) { return curr_ != rhs.curr_;}
private:
    // 检查StrBlob所指向对象是否为空以及指针下标操作是否超出范围
    std::shared_ptr<std::vector<std::string>>  
         check(std::size_t index, const std::string &msg) const;
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t curr_;
};
#endif
