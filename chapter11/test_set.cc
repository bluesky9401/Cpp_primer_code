#include <iostream>
using std::cout;
using std::endl;
#include <set>
using std::set;
#include <string>
using std::string;

int main()
{
    set<string>::key_type name;
    decltype(name) data;
    name = "chentongjie";
    cout << name << endl;
    return 0;
}
