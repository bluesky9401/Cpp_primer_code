#include <iostream>
#include <string>
#include "SalesData.h"

int main()
{
    SalesData item1(std::string("123445"));
    SalesData item2(std::string("123434"),1 ,12, 12);
    SalesData item3(std::cin);

    std::cout << "the item1 information:\n" ;
    print(std::cout, item1);
    std::cout << "the item2 information:\n";
    print(std::cout, item2);
    std::cout << "the item3 information:\n";
    print(std::cout, item3);
    return 0;
}
