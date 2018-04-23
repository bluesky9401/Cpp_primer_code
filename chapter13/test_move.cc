#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "StrVec.h"

int main()
{
    StrVec strvec1;
    string str;
    while(cin >> str) {
        strvec1.push_back(str);
        cout << "current size: " <<strvec1.size();
        cout << "current capacity: " << strvec1.capacity() << endl;
    }
}

