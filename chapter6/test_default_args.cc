#include <iostream>
using std::cout;
using std::endl;

void print(int i, int j, int k = 0);
void print(int i, int j = 0, int k);

int main()
{
    int val = 0;
    print(val);
    return 0;
}

void print(int i, int j, int k)
{
    cout << "call containing default args function 1" << endl;
}
