#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

vector<string> retInf()
{
    return {"chen", "tong", "jie"};
}

int main()
{
    auto svec = retInf();
    for(auto &elem: svec)
        cout << elem << endl;
    return 0;
}
