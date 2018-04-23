#include "Quote.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

double printTotal(std::ostream &os, const DisQuote &item, size_t n)
{
    double ret = item.netPrice(n);
    os << "ISBN: " << item.getIsbn() 
       << "sold: " << n 
       << "revenue: " << ret
       << endl;
    return ret;
}
