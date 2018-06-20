#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <list>
using std::list;

int main()
{
    vector<string> strvec{"chen", "tong", "jie"};
    list<string> strlst{"ni", "hao", "a"};

    auto iter = strvec.insert(strvec.begin()+1, 3, "wo");
    cout << *iter << " " << *iter++ << endl;
    return 0;
}
