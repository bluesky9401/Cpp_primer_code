#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include <fstream>
#include <memory>
#include <string>
#include <set>
#include <map>
#include "QueryResult.h"
class QueryResult;
class TextQuery{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery() = default;
    TextQuery(std::ifstream &fis);
    QueryResult query(const std::string &str) const;
    void displayMap() const; 
private:
    std::shared_ptr<std::vector<std::string>> ptr_file_;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> map_string_to_line_;
    static void cleanUpAndPunc(std::string &word);
};
#endif
