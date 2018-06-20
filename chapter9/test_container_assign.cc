#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

int main()
{
    vector<string> strvec1{"chen", "tong", "jie"};
    cout << "strvec1 size: "<< strvec1.size()
         << "strvec1 capacity: " << strvec1.capacity() << endl;
    vector<string> strvec2{"ni"};
    cout << "strvec2 size: "<< strvec2.size()
         << "strvec2 capacity: " << strvec2.capacity() << endl;
    strvec1 = strvec2;
    cout << "strvec1 size: "<< strvec1.size()
         << "strvec1 capacity: " << strvec1.capacity() << endl;
    return 0;
}
