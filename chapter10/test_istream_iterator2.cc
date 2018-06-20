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
    istream_iterator<string> iter_str1(cin), end;
    istream_iterator<string> iter_str2(cin);

    cout << *iter_str1++ << endl;
    cout << *iter_str2 << endl;

    return 0;

}
