#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <iostream>
#include <string>

/** 基类 **/
class Quote {
    friend double printTotal(std::ostream &os, const Quote &item, size_t n);
public:
    // 构造函数
    Quote() = default;
    Quote(const std::string &num, double p): book_number_(num), price_(p) { }
    // 拷贝构造函数
    Quote(const Quote &obj): book_number_(obj.book_number_), price_(obj.price_) { }
    // 移动构造函数
    Quote(Quote &&obj): book_number_(obj.book_number_), price_(obj.price_) { }
    // 返回书籍的总价
    virtual double netPrice(size_t n) const { return n*price_; }
    // 返回指向拷贝对象的指针
    virtual Quote* clone() const & { return new Quote(*this); }
    // 返回指向移动对象的指针
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
    // 返回书籍的ISBN
    std::string getIsbn() const { return book_number_; }
    ~Quote() = default;
private:
    std::string book_number_;
protected:
    double price_ = 0;    
};
// 友元函数声明
double printTotal(std::ostream &os, const Quote &item, size_t n);


/** 派生类 **/
class DisQuote : public Quote{
public: 
    // 构造函数
    DisQuote() = default;
    DisQuote(const std::string &num, double p, size_t q, double disc): 
            Quote(num, p), quantity_(q), discount_(disc) { }
    // 拷贝构造函数
    DisQuote(const DisQuote &obj): Quote(obj), quantity_(obj.quantity_), discount_(obj.discount_) { }
    // 移动构造函数
    DisQuote(DisQuote &&obj): Quote(obj), quantity_(obj.quantity_), discount_(obj.quantity_) { }
    // 返回书籍总价
    double netPrice(size_t n) const = 0;
    ~DisQuote() = default;
protected: 
    size_t quantity_ = 0;
    double discount_ = 0;
};

class BulkQuote: public DisQuote {
public:
    //构造函数
    BulkQuote() = default;
    BulkQuote(const std::string &num, double p, size_t mq, double d): DisQuote(num, p, mq, d) { }
    // 拷贝构造函数
    BulkQuote(const BulkQuote &obj): DisQuote(obj) { }
    // 移动构造函数
    BulkQuote(BulkQuote &&obj): DisQuote(obj) { }
    // 返回书籍总价
    double netPrice(size_t n) const override;
    // 返回指向拷贝对象的指针
    virtual BulkQuote* clone() const & override { return new BulkQuote(*this); }
    // 返回指向移动对象的指针
    virtual BulkQuote* clone() && override { return new BulkQuote(std::move(*this)); }
    ~BulkQuote() = default;
};
inline double BulkQuote::netPrice(size_t n) const
{
    return n >= quantity_ ? n*(1-discount_)*price_ : n*price_;
}

class LimitQuote: public DisQuote {
public:
    // 构造函数
    LimitQuote() = default;
    LimitQuote(const std::string &num, double p, size_t lq, double d): DisQuote(num, p ,lq, d) { }
    // 拷贝构造函数
    LimitQuote(const LimitQuote &obj): DisQuote(obj) { }
    // 移动构造函数
    LimitQuote(LimitQuote &&obj): DisQuote(obj) { }
    // 返回书籍总价
    double netPrice(size_t n) const override;
    // 返回指向拷贝对象的指针
    LimitQuote* clone() const & override { return new LimitQuote(*this); }
    // 返回指向移动对象的指针
    LimitQuote* clone() && override { return new LimitQuote(std::move(*this)); }
    ~LimitQuote() = default;
};
inline double LimitQuote::netPrice(size_t n) const
{
    return n <= quantity_ ? n*(1-discount_)*price_ : (quantity_*(1-discount_)*price_ + (n-quantity_)*price_);
}
#endif
