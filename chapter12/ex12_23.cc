#include <iostream>
#include <memory>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    char *Contact_const_string = new char[strlen("hello ""world"+1)]();
    strcat(Contact_const_string, "hello ");
    strcat(Contact_const_string, "world");
    cout << Contact_const_string << endl;
    delete [] Contact_const_string;
    return 0;
}
