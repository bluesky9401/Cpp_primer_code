#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iterator>
#include <algorithm>

int main()
{
    vector<string> svec1;
    vector<string> svec2;
    string str;
    while (cin >> str)
        svec1.push_back(str);

    std::sort(svec1.begin(), svec1.end());
    std::unique_copy(svec1.begin(), svec1.end(), std::back_inserter(svec2));

    cout << "the element of svec1: \n";
    for (auto &element: svec1)
        cout << element << " ";
    cout << endl;
    
    cout << "the element of svec2: \n";
    for (auto &element: svec2)
        cout << element << " ";
    cout << endl;

    return 0;
}
