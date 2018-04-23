#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <iostream>
using std::ostream;
#include <iterator>
#include "Quote.h"
#include "Basket.h"

void Basket::addItem(const Quote &item)
{
    items_.insert(shared_ptr<Quote>(item.clone()));
}

void Basket::addItem(Quote &&item)
{
    items_.insert(shared_ptr<Quote>(item.clone()));
}

double Basket::totalReceipt(ostream &os)
{
    double sum;    
    for(auto iter = items_.cbegin(); 
        iter != items_.cend(); iter = items_.upper_bound(*iter)) {
        sum += printTotal(os, **iter, items_.count(*iter));
    }
    return sum;
}
