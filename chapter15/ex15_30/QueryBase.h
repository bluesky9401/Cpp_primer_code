#ifndef _QUERYBASE_H_
#define _QUERYBASE_H_
#include "TextQuery.h"
#include "QueryResult.h"
class Query;
class QueryBase {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;
private:
    // 返回与当前query匹配的QueryResult
    virtual QueryResult eval(const TextQuery &text) const = 0;
    // rep是表示查询的一个string
    virtual std::string rep() const = 0;
};
#endif
