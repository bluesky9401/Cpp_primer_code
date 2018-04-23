#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string strInput;
	while (cin){
		std::getline(cin,strInput);
		cout << strInput << endl;
	}
	return 0;
}
