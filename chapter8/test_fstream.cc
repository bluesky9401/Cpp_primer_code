#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;

int main()
{
    ifstream ifs("test.txt");
    ifs.is_open() ? cout << "open success!" : cout << "open fail!";
    return 0;
}
