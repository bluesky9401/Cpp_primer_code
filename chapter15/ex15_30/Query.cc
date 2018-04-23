#include "Query.h"
#include "WordQuery.h"
#include <memory>
using std::shared_ptr;

Query::Query(std::string &word)
{
    ptr_QueryBase_ = shared_ptr<QueryBase>(new WordQuery(word));
}
