#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>
using std::map;
#include <functional>
using std::function;

int add(int lhs, int rhs) { return lhs + rhs; }
int 
int minus(int lhs, int rhs) { return lhs - rhs; }
class mod{
public: 
    int operator ()(int lhs, int rhs) const{ return lhs%rhs; }
};

map<string, function<int(int, int)>> calculator = {
        {"+", add},
        {"-", minus},
        {"*", std::multiplies<int>() },
        {"/", [] (int lhs, int rhs) {return lhs/rhs; } },
        {"%", mod()} };
int main()
{
    while (cout << "please enter in format: lhs operator rhs: ") {
        int lhs;
        int rhs;
        string op;
        cin >> lhs >> op >> rhs;
        cout << "the result is " << calculator[op](lhs, rhs) << endl; 
    }
    return 0;
}
