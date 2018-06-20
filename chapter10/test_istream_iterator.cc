#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iterator>
using std::istream_iterator;

int main()
{
    int count = 0;
    vector<string> svec;
    string str;
    istream_iterator<string> iter_str(cin), end;

    while (count != 2) {
        cin >> str;
        svec.push_back(str);
        ++ count;
    }
    cout << endl;
    while (iter_str != end)
        cout << *iter_str++ << endl;

    return 0;

}
