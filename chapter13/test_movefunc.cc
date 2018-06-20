#include <iostream>
#include <utility>

int main()
{
    int rr1 = 1;
    int &&rr3 = std::move(rr1);
    int rr4 = rr3;
    std::cout << rr1 << std::endl;
    return 0;
}
