#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iterator>

int main()
{
    vector<string> strvec{"chen", "tong", "jie","ni","hao","a"};
    string str("chentongjie");
    deque<string> strdeq(strvec.cbegin(), strvec.cend());
    strvec.insert(strvec.begin()+1, "nihaoa");    
    cout << "vector " << "size " << strvec.size() << "\n"
                      << "capacity " << strvec.capacity() << endl;
    cout << "string " << "size " << str.size() << "\n"
                      << "capacity " << str.capacity() << endl;
    cout << "deque " << "size " << strdeq.size() << "\n";
  
    strvec.shrink_to_fit();
    str.shrink_to_fit();
    strdeq.shrink_to_fit();
   
    cout << "vector " << "size " << strvec.size() << "\n"
                      << "capacity " << strvec.capacity() << endl;
    cout << "string " << "size " << str.size() << "\n"
                      << "capacity " << str.capacity() << endl;
    cout << "deque " << "size " << strdeq.size() << "\n";
}
