#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iterator>
#include <string>
using std::string;
#include <vector>
using std::vector;

int main()
{
    vector<string> svec{"chen", "tong", "jie"};
    string str;
    auto iter = inserter(svec, svec.begin()+svec.size()/2);
    
    while(cin >> str)
        *iter = str;
    
    for(auto &elem : svec)
        cout << elem << endl;
    return 0;
}
