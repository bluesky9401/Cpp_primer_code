#ifndef _WORDQUERY_H_
#define _WORDQUERY_H_
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
#include "QueryBase.h"

class Query;
class WordQuery: public QueryBase{
    friend class Query;
    WordQuery(const std::string word): query_word_(word) { }

    QueryResult eval(const TextQuery &text) const override
                { return text.query(query_word_);}
    std::string rep() const override
                { return query_word_; }

    std::string query_word_;

};
#endif
