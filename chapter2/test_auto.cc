#include <iostream>
using std::cout;
using std::endl;
#include <typeinfo>

int main()
{
    const int nval = 0;
    const int &refval = nval;
    auto &i = nval;
    auto j = refval;
    cout << "the type of i: " << typeid(i).name() << '\n';
    cout << "the type of j: " << typeid(j).name() << endl;
    return 0;
}
