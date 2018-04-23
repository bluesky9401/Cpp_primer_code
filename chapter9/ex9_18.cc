#include <iostream>
#include <string>
#include <deque>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;

int main() 
{
    std::string str_input;
    std::deque<std::string> strdeque_input;
    while (cin >> str_input){
        strdeque_input.push_back(str_input);    
    }
    for(auto iter = strdeque_input.cbegin(); iter != strdeque_input.cend(); ++iter){
        cout << *iter << ' ';
    }
    cout << '\n' << endl;
    return 0;
}
