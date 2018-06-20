#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <initializer_list>
using std::initializer_list;

class myclass {
public:
    myclass() = default;
    myclass(string data, string sz_str):data_(data) 
                {   *sz_str_ = sz_str;
                    cout << "call myclass(int) function" << endl; }

    string data_;  
    string sz_str_[10];
};
int main()
{
    myclass data1("chen", "tong");
    myclass data2(data1);
    cout << *(data2.sz_str_) << endl;
    return 0;
}
