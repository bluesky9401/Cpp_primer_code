#include <iostream>
#include <string>
#include "StrVec.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string strValue;
    StrVec strvec_input;
    cout << "please input the string: " << endl;
    while(std::cin >> strValue){
        strvec_input.push_back(strValue);
    }
    cout << "size: " << strvec_input.size() 
         << "capacity: " << strvec_input.capacity() << endl;
    for(auto &element: strvec_input){
        cout << element << ' ';
    }
    cout << endl;
    strvec_input.resize(3);
    cout << "size: " << strvec_input.size() << endl;
    return 0;
}
