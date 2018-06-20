#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

int main()
{
    vector<string> strvec{"chen", "tong", "jie"};
    cout << strvec.size() << " " 
         << strvec.capacity() << endl;
    strvec.clear();
    cout << strvec.size() << " " 
         << strvec.capacity() << endl;
    
    return 0;
}
