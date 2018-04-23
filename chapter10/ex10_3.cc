#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using std::cout;
using std::endl;

int main()
{
    std::vector<int> nvec = {1, 2, 3};
    auto result = accumulate(nvec.cbegin(), nvec.cend(), 0);
    cout << result << endl;
    return 0;
}
