#include <iostream>
#include <string>
#include <typeinfo>
int main()
{
    std::cout << "the size_type is: " << typeid(std::string::size_type).name() << std::endl;
    return 0;
}
