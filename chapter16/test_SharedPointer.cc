#include <string>
using std::string;
#include "SharedPointer.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    SharedPointer<string> sp1_str(new string("chentongjie"));
    SharedPointer<string> sp2_str(sp1_str);
    cout << *sp1_str << sp1_str.use_count() <<endl;
    SharedPointer<string> sp3_str(new string("ni hao"));
    sp2_str = sp3_str;
    cout << *sp1_str << "count " << sp1_str.use_count() << "\n";
    cout << *sp3_str << "count " << sp2_str.use_count() << endl; 
    return 0;
}

