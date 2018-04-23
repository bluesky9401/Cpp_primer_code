#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>
class Person{
// friend function
friend std::istream& read(std::istream &is, Person &item);
friend std::ostream& print(std::ostream &os, Person &item);
public:
          // constructor function
          Person() = default;
          Person(std::string strname, std::string straddr):m_name(strname), m_addr(straddr);
          Person(Person &person_information) = default;
          Person(std::istream &is) { read(is, *this); }

          std::string name() const {return m_name;}
          std::string addr() const {return m_addr;}
private:
          std::string m_name;
          std::string m_addr;
};
std::istream& read(std::istream &is, Person &item);
std::ostream& print(std::ostream &os, Person &item);
#endif
