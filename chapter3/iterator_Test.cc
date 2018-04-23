#include <iostream>
#include <string>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::iterator;
using std::string;
int main()
{
	string strInput;
	while (cin >> strInput){
		auto it = strInput.begin();
		for (;it != strInput.end(); ++it){
			if (islower(*it)){
				*it = toupper(*it);
			} 
		cout << strInput << endl;
		}
	}
}
