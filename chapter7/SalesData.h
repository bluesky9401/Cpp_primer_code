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
  private:
          std::string m_book_number;
          unsigned m_unit_sold = 0;
          double m_price = 0.0;
          double m_revenue = 0.0;
};
std::ostream& print(std::ostream &os, SalesData &data);
std::istream& read(std::istream &is, SalesData &data);
SalesData add(const SalesData &lhs, const SalesData &rhs);
#endif

