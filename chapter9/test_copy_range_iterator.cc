#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <iterator>

int main()
{
    int data;
    vector<int> strdata;
    while (cin >> data) 
        strdata.push_back(data);
    deque<double> deqdata(strdata.cbegin(), strdata.cend());
    for (auto &element: deqdata)
        cout << element << endl;

    return 0;
}

