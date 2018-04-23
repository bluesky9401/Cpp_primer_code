#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	string strInput;
	vector<string> svecInput;
	while (cin >> strInput){
	
		svecInput.push_back(strInput);
	}
	for(auto element: svecInput){
	    cout << element << endl;
	}
	return 0;
}
