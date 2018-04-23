#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class SalesData{
  public:
          // friend function
          friend std::istream& read(std::istream &is, SalesData &data);
          friend std::ostream& print(std::ostream &os, SalesData &data);
          friend SalesData add(const SalesData &lhs, const SalesData &rhs);
          friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
          friend std::ostream& operator<<(std::ostream &os, SalesData &rhs);
          friend std::istream& operator>>(std::istream &is, SalesData &rhs);
          // constructor function
          SalesData() = default;
          SalesData(std::string s):m_book_number(s){}
          SalesData(std::string s,unsigned sold, double price, double revenue):
                  m_book_number(s), m_unit_sold(sold), m_price(price), m_revenue(revenue) {}
          SalesData(std::istream &is)
          {
             read(is, *this);
          }
          std::string isbn() const;
          SalesData& combine(const SalesData &rhs);
          SalesData& operator=(SalesData &rhs);
          inline SalesData& operator+=(const SalesData &rhs);
  private:
          std::string m_book_number;
          unsigned m_unit_sold = 0;
          double m_price = 0.0;
          double m_revenue = 0.0;
};
// 友元函数声明
std::ostream& print(std::ostream &os, SalesData &data);
std::istream& read(std::istream &is, SalesData &data);
SalesData add(const SalesData &lhs, const SalesData &rhs);
SalesData operator+(const SalesData &lhs, const SalesData &rhs);
std::ostream& operator<<(std::ostream &os, SalesData &rhs);
std::istream& operator>>(std::istream &is, SalesData &rhs);

// 内联函数定义在头文件
inline SalesData::SalesData& operator+=(const SalesData &rhs)
{
    if (m_book_number != rhs.m_book_number) {
        std::cerr << "can not match book number, the plus operate fail!" << std::endl;
    } else {
        m_unit_sold += rhs.m_unit_sold;
        m_revenue  += rhs.m_revenue;
    }
    return *this;
}

#endif

