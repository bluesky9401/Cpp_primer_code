#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    // print the type infomation of i j k p j2 k2
    cout << "the type of j is "     << typeid(i).name();
    cout << "\n the type of j is "  << typeid(j).name();
    cout << "\n the type of k is "  << typeid(k).name();
    cout << "\n the type of p is "  << typeid(p).name();
    cout << "\n the type of j2 is " << typeid(j2).name();
    cout << "\n the type of k2 is " << typeid(k2).name();
    cout << endl;

    cout << "the value of p is " << p << endl;
    return 0;
}
