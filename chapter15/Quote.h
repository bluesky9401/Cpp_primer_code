#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <iostream>
#include <string>

/** 基类 **/
class Quote{
public:
    Quote() { std::cout << "Quote: default constructor run!" << std::endl; }
    Quote(const std::string &num, double p): book_number_(num), price_(p) 
        { std::cout << "Quote: constructor take two parameters run!" << std::endl; }
    Quote(const Quote &obj): book_number_(obj.book_number_), price_(obj.price_) 
        { std::cout << "Quote: copy constructor run!" << std::endl; }

    std::string getIsbn() const { return book_number_; }
    ~Quote() { std::cout << "Quote: running the desturcotr!" << std::endl; }
private:
    std::string book_number_;
protected:
    double price_ = 0;    
};


/** 派生类 **/
class DisQuote : public Quote{
    friend double printTotal(std::ostream &os, const DisQuote &item, size_t n);
public: 
    DisQuote() { std::cout << "DisQuote: default constructor run! " << std::endl; }
    DisQuote(const std::string &num, double p, size_t q, double disc): Quote(num, p), quantity_(q), discount_(disc)
        {std::cout << "DisQuote: constructor take four parameter run! " << std::endl; }
    virtual double netPrice(size_t n) const = 0;
    ~DisQuote() { std::cout << "DisQuote: running the destructor! " << std::endl; }
protected: 
    size_t quantity_ = 0;
    double discount_ = 0;
};
// 友元函数声明
double printTotal(std::ostream &os, const DisQuote &item, size_t n);

class BulkQuote: public DisQuote {
public:
    BulkQuote() = default;
    BulkQuote(const std::string &num, double p, size_t mq, double d): DisQuote(num, p, mq, d)
        { std::cout << "BulkQuote: constructor take four parameter run! " << std::endl; }
    virtual double netPrice(size_t n) const override;
    ~BulkQuote() { std::cout << "BulkQuote: running the destructor!" << std::endl; }
};
inline double BulkQuote::netPrice(size_t n) const
{
    return n >= quantity_ ? n*(1-discount_)*price_ : n*price_;
}

class LimitQuote: public DisQuote {
public:
    LimitQuote() { std::cout << "LimitQuote: default constructor run!" << std::endl; }
    LimitQuote(const std::string &num, double p, size_t lq, double d): DisQuote(num, p ,lq, d)
        {std::cout << "LimitQuote: constructor take four parameter run!" << std::endl; }
    virtual double netPrice(size_t n) const override;
    ~LimitQuote() { std::cout << "LimitQuote: running the destructor!" << std::endl; }
};
inline double LimitQuote::netPrice(size_t n) const
{
    return n <= quantity_ ? n*(1-discount_)*price_ : (quantity_*(1-discount_)*price_ + (n-quantity_)*price_);
}
#endif
