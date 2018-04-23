#ifndef _QUERY_H_
#define _QUERY_H_
#include <string>
#include <memory>
#include "TextQuery.h"
#include "QueryResult.h"
#include "QueryBase.h"

class Query {
    friend Query operator~(const Query &obj);
    friend Query operator|(const Query &lhs, const Query &rhs);
    friend Query operator&(const Query &lhs, const Query &rhs);
public:
    Query(std::string &word);// 构建一个新的WordQuery对象
    // 接口函数：调用对应的QueryBase操作
    QueryResult eval(const TextQuery &text) const
            { return ptr_QueryBase_ -> eval(text); }
    std::string rep() const {return ptr_QueryBase_ -> rep();}
private:
    // 应用于在进行操作～|&时构建一个query对象
    Query(std::shared_ptr<QueryBase> ptr): ptr_QueryBase_(ptr) { }
    std::shared_ptr<QueryBase> ptr_QueryBase_;
};
#endif
