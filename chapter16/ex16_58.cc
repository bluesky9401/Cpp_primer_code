#include <iostream>
#include "StrVec.h"

int main()
{
    StrVec str;
    str.emplace_back(10,'c');
    std::cout << *(str.begin()) << std::endl;
    return 0;
}
