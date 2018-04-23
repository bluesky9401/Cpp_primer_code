#ifndef _BINARYQUERY_H_
#define _BINARYQUERY_H_
#include <string>
#include "QueryBase.h"
#include "Query.h"
class BinaryQuery :public QueryBase {
protected: 
    BinaryQuery(const Query &lhs, const Query &rhs, std::string s):
                lhs_(lhs), rhs_(rhs), opSym_(s) { }
    std::string rep() const override 
    { return "(" + lhs_.rep(), + " "
                                   + opSym_ + " "
                                   + rhs_.rep() + ")"; }
    Query lhs_, rhs_;
    std::string opSym_;// 运算符的名字
};
#endif
