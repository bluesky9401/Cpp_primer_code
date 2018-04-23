#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int nValue1, nValue2;
    int nMultiValue=10;
    int nresult;
    auto sum = [nMultiValue] (int rhs, int lhs) -> int {return (rhs + lhs)*nMultiValue;};
    while (cin >> nValue1 >> nValue2){
        nresult = sum(nValue1,nValue2);
        cout << "the result is: " << nresult << endl;
    }
    return 0;
}
