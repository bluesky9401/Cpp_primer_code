#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    std::string strHexDigital= {"0123456789ABCDEF"};
    std::string strResult;
    std::string::size_type num;
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished"
         << endl;
    while (cin >> num){
        if (num < strHexDigital.size()){
            strResult += strHexDigital[num];
        }//ignore the invalid input
    }
    cout << "Your Hex number is: " << strResult << endl;
    return 0;
}
