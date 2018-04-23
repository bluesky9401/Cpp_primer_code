#ifndef _BASKET_H_
#define _BASKET_H_

#include <set>
#include <memory>
#include <iostream>
#include "Quote.h"

class Basket {
public:
    Basket() = default;
    void addItem(const Quote &item);
    void addItem(Quote &&item);
    double totalReceipt(std::ostream &os);
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, 
                        const std::shared_ptr<Quote> &rhs) { return lhs->getIsbn() < rhs->getIsbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items_{compare};
};
#endif
