#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;

int main()
{
    std::vector<int> nvec = {1 ,2 ,5, 6, 7, 10};
    auto result = find(nvec.cbegin(), nvec.cend(), 7);
    cout << *result << endl;
    return 0;
}
