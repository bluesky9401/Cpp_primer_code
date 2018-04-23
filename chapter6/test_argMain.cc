#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
int main(int argc, char *argv[])
{
	string strArg1 = argv[1];
	string strArg2 = argv[2];
	string strCombine = strArg1 + strArg2;
	cout << argv[0] << std::endl;
	cout << strCombine << std::endl;
	return 0;

}
