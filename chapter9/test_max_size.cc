#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>

using std::cout;
using std::endl;

int main()
{
    std::vector<int> nvecValue;
    std::vector<std::string> strvecValue;
    std::deque<int> ideValue;
    std::list<int> nlistValue;
    cout << "the max size of nvector" << nvecValue.max_size() << endl;
    cout << "the max size of strvector" << strvecValue.max_size() << endl;
    cout << "the max size of ndeque" << ideValue.max_size() << endl;
    cout << "the max size of nlist" << nlistValue.max_size() << endl;
}
