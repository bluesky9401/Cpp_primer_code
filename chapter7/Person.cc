#include "Person.h"
#include <iostream>
std::istream& read(std::istream &is, Person &item)
{
    std::cin >> item.m_name >> item.m_addr;
    return is;
}
std::ostream& print(std::ostream &os, Person &item)
{
    std::cout << "person name: " << item.m_name << '\n'
              << "person address: " << item.m_addr << std::endl;
    return os;
}
