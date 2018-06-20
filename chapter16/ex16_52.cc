#include <iostream>
using std::cout;
using std::endl;

template <typename T, typename... Args> void foo(const T &t, const Args& ... rest)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

int main()
{
    foo(1, 2, 3, 4);
    foo(1, 2, 3, 4, 5);
    return 0;
}
