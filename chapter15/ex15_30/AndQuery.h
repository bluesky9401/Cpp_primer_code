#ifndef _ANDQUERY_H_
#define _ANDQUERY_H_
#include <memory>
#include "BinaryQuery.h"
#include "Query.h"
class AndQuery: public BinaryQuery{
    friend Query operator&(const Query& lhs, const Query& rhs);
    AndQuery(const Query &lhs, const Query &rhs): 
                BinaryQuery(lhs, rhs, "&") { }
    QueryResult eval(const TextQuery &text) const override;
    
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}
#endif
