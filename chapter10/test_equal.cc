#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <string>
using std::string;
#include <algorithm>
using std::equal;

int main()
{
    vector<string> svec{"chen", "tong", "jie"};
    list<const char*> lstvec{"chen", "tong", "jie"};
    auto result = equal(svec.cbegin(), svec.cend(), lstvec.cbegin());
    cout << result << endl;
    return 0;
}
