#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class myclass {
public:
    myclass() = default;
    myclass(string data):data_(data) 
                { cout << "call myclass(int) function" << endl; }

private:
    string data_;    
};
myclass::myclass()
{
    cout << " call default constructor function" << endl;
}
int main()
{
    myclass data;
    return 0;
}
