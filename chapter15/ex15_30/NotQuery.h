#ifndef _NOTQUERY_H_
#define _NOTQUERY_H_
#include "QueryBase.h"
#include "Query.h"
class QueryResult;
class NotQuery: public QueryBase {
    friend Query operator~(const Query &operand);
    friend class Query;
    NotQuery(const Query &q): query_(q) { }
    
    QueryResult eval(const TextQuery &text) const override;
    std::string rep() const override
            { return "~(" + query_.rep() + ")"; }
    Query query_;
};
inline Query operator~(const Query &operand)
        { return std::shared_ptr<QueryBase>(new NotQuery(operand)); }
#endif
