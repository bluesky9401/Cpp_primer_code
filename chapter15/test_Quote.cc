#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include "Quote.h"

int main()
{
   
    BulkQuote item2(string("1234567"), 25, 3, 0.2);
    LimitQuote item3(string("12346578"), 30, 1, 0.1); 
    printTotal(cout, item2, 4);
    printTotal(cout, item3, 5);

}
