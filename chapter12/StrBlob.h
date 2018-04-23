#ifndef _STRBLOB_H_
#define _STRBLOB_H_
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>() ) { }
    StrBlob(std::initializer_list<std::string> initial_list): data(std::make_shared<std::vector<std::string>>(initial_list) ) { }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &str) { data->push_back(str); }
    void pop_back() 
    {
        check(0,"pop back on empty StrBlob");
        data->pop_back();
    }    
    std::string& front()
    {
        check(0,"front on empty StrBlob");
        return data->front();
    }
    std::string& back()
    {
        check(0,"back on empty StrBlob");
        return data->back();
    }
    std::string& front() const
    {
        check(0,"front on empty StrBlob");
        return data->front();
    }
    std::string& back() const
    {
        check(0,"back on empty StrBlob");
        return data->back();
    }
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    void check(size_type i, const std::string &msg) const
    {
        if(i >= data->size())
            throw std::out_of_range(msg);
    }
    std::shared_ptr<std::vector<std::string>> data;
};
#endif
