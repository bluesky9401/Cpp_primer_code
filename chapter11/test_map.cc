#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;

int main()
{
    map<string, string> name = { {"chen", "tongjie"},
                                 {"chen", "jisheng"},
                                 {"chen", "tongjie"} };
    cout << name["chen"] << endl;
}
