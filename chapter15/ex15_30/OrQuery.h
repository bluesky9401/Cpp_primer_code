#ifndef _ORQUERY_H_
#define _ORQUERY_H_
#include <memory>
#include "BinaryQuery.h"
#include "Query.h"
class OrQuery: public BinaryQuery {
    friend Query operator|(const Query &lhs, const Query &rhs);
    OrQuery(const Query &lhs, const Query &rhs): 
            BinaryQuery(lhs, rhs, "|") { }
    QueryResult eval(const TextQuery &text) const override;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}
#endif
