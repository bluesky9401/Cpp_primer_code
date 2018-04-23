#include <iostream>
#include "Person.h"
int main()
{
    Person person_information;
    while (read(std::cin, person_information)){
        print(std::cout, person_information);
    }
    return 0;
}
