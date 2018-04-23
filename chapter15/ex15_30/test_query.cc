#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "TextQuery.h"
#include "QueryResult.h"

int main(int argc, char *argv[])
{
    ifstream fis(argv[1]);
    TextQuery text(fis);
    string word("Daddy");
    QueryResult result = text.query(word);
    print(cout, result);
}
