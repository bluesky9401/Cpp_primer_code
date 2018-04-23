#include <iostream>
using std::cout;
#include "Quote.h"

int main()
{
    Quote item_nondiscount("12345", 25);
    BulkQuote item_discount("231", 15, 3, 0.2);
    printTotal(cout, item_nondiscount, 3);
    printTotal(cout, item_discount, 4);
    return 0;
}
