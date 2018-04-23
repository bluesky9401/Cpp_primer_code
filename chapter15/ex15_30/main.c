#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "BinaryQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include <fstream>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::ifstream;

int main(int argc, char *argv[])
{
    ifstream ifs(argv[1]);
    TextQuery text(ifs);
    string word1("says"), word2("hair");
    Query search = Query(word1)|Query(word2);
    QueryResult result = search.eval(text);
    print(cout, result);
    return 0;
}

