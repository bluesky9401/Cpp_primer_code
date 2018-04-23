#include <iostream>
#include <vector>
using std::cout;
using std::endl;
int main()
{
    std::vector<int> nvec_value1 = {1,2,3};
    std::vector<int> nvec_value2 = {1,2};
    std::vector<int> nvec_value3 ={1,2,3};
    cout << (nvec_value1 == nvec_value2 ? "ture" : "false") << endl;
    cout << (nvec_value1 == nvec_value3 ? "ture" : "false") << endl;
    return 0;
}
