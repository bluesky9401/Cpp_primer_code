#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "Vec.h"

int main()
{
    Vec<string> strvec = {"chen", "tong", "jie"};
    strvec.push_back("hao");
    auto end = strvec.end();
    for(auto beg = strvec.begin(); beg != end; ++beg) {
        cout << *beg << endl; 
    }
    cout << strvec.size() << endl;
}

