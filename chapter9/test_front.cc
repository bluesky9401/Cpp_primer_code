#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

int main()
{
    vector<string> strvec{"chen", "tong", "jie"};
    auto &ref = strvec.front();
    cout << ref << endl;
    ref = "yang";
    cout << *strvec.cbegin() << endl;
    return 0;
}
