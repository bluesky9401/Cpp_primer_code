#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
template<typename T> int compare(const T &lhs, const T &rhs) //the function template of compare
{
	if(lhs < rhs){
	    return 1;
	}
	if(rhs < lhs){
	    return 0;
	}
	return  -1;
}
int main()
{
    int nCompareNum1;
    int nCompareNum2;
    int nResultNum;
    int nResultVector;
    vector<string> vec_strCompareString1 = {"chen","tong","jie"}, vec_strCompareString2 = {"chen","komg"};
    nResultVector = compare(vec_strCompareString1,vec_strCompareString2);
    cout << nResultVector << endl;
    return 0;    
}
