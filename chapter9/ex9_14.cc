#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>

using std::cout;
using std::endl;

int main()
{
    std::list<const char *> list_string = {"chen", "tong", "jie"};
    std::vector<std::string> vec_string;
    vec_string.assign(list_string.cbegin(), list_string.cend());
    for(auto &element: vec_string){
        cout << element << endl;    
    }
    return 0;
}
