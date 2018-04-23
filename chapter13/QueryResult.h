#ifndef _QUERYRESULT_H_
#define _QUERYRESULT_H_

#include <string>
#include <set>
#include <memory>
#include <vector>
#include <iterator>
#include <iostream>

class QueryResult{
    friend void print(std::ostream &os, const QueryResult &result);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::iterator iter_set;

    QueryResult(std::string str,
                std::shared_ptr<std::set<line_no>> ptr_l,
                std::shared_ptr<std::vector<std::string>> ptr_f): 
                sought_(str), ptr_sought_position_(ptr_l), ptr_file_(ptr_f) { }

    std::set<line_no>::size_type size() const { return ptr_sought_position_->size(); }
    iter_set cbegin() const { return ptr_sought_position_->cbegin(); }
    iter_set cend() const { return ptr_sought_position_->cend(); }

    std::shared_ptr<std::vector<std::string>> get_file() { return ptr_file_; }
private:
    std::string sought_;
    std::shared_ptr<std::set<line_no>> ptr_sought_position_;
    std::shared_ptr<std::vector<std::string>> ptr_file_;    
};
void print(std::ostream &os, const QueryResult &result);
#endif
