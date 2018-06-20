#include <iostream>

constexpr int add(int i, int j)
{
    return j;
}

int main()
{
    constexpr int i = 2;
    int result = add(i, 2);
    return 0;
}
