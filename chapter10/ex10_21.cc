#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int nvalue = 10;
    auto check_and_decrease = [&nvalue] {return --nvalue ? false : true;};
    while (!check_and_decrease()) {
        cout << nvalue << " ";
    }
    cout << endl;
    return 0;
}
