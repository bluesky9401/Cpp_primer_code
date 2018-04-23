#include "OrQuery.h"
#include "QueryResult.h"
#include <memory>
using std::make_shared;
#include <set>
using std::set;

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs_.eval(text), left = lhs_.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.getFile());
}
