#include <iostream>
#include <vector>
#include <list>
using std::cout;
using std::endl;
int main()
{
    std::vector<int> nvec_value1 = {1,2,3};
    std::list<int> nvec_value2 = {1,2};
    std::list<int> nvec_value3 ={1,2,3};
    cout << (std::list<int> (nvec_value1.cbegin(), nvec_value1.cend()) == nvec_value2 ? "ture" : "false") << endl;
    cout << (std::list<int> (nvec_value1.cbegin(), nvec_value1.cend()) == nvec_value3 ? "ture" : "false") << endl;
    return 0;
}
