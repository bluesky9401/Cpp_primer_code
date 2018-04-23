#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "Quote.h"

int main()
{
    BulkQuote item1;
    BulkQuote item2(string("123465"), 12.0, 3, 0.2);
    return 0;
}
