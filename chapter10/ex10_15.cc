#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int nvalue1;
    nvalue1 = 2;
    auto sum = [nvalue1] (int nvalue2) {return nvalue1 + nvalue2;};
    cout << sum(4) << endl;
    return 0;
}
