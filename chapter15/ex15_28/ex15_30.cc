#include <iostream>
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include "Quote.h"
#include "Basket.h"

int main()
{
    Quote item1(string("100"), 25);
    BulkQuote item2(string("101"), 30, 3, 0.2);
    LimitQuote item3(string("103"), 40, 2, 0.2);
    Basket items;
    items.addItem(item1);
    items.addItem(item2);
    items.addItem(item3);
    items.totalReceipt(std::cout);
    return 0;
}
