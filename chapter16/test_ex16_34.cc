#include <iostream>

template <typename T> bool compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs) return -1;
    if (rhs < lhs) return 0;
    return 0;
}

int main()
{
    bool result1 = compare("hi", "world");
    bool result2 = compare("bye", "dad");
    return 0;
}
