#include "NotQuery.h"
#include "QueryResult.h"
#include <memory>
using std::make_shared;
#include <set>
using std::set;

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query_.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto TextLineNum = result.getFile()->size();

    for(size_t n = 0; n != TextLineNum; ++n) {
        if(beg == end || *beg != n) {
            ret_lines->insert(n);
        } else if(beg != end) {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.getFile());
}
