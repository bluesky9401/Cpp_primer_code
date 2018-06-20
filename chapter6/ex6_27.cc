#include <iostream>
using std::cout;
using std::endl;
#include <initializer_list>
using std::initializer_list;

int add(initializer_list<int> lst)
{   
    int sum = 0;
    for(auto &element: lst)
        sum += element;
    return sum;
}
int main()
{
    cout << add({1, 2, 3, 4, 5}) << endl;
    return 0;
}
