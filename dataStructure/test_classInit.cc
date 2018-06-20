#include <iostream>
using std::cout;
using std::endl;

class Data {
public:
    void printData() { cout << i << endl; }
private:
    int i = 0;
    int j = 0;
};

int main()
{
    Data data;
    data.printData();
    return 0;
}
