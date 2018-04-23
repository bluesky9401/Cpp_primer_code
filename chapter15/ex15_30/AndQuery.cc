#include "AndQuery.h"
#include <memory>
using std::make_shared;
#include <set>
#include <algorithm>
using std::set;

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs_.eval(text), left = lhs_.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.getFile());

}
