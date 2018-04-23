#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int size{ 0 };
    cout << "please enter the length of string you want to input: " << endl;
    cin >> size;
    char *ptr = new char[size+1]();
    cin.ignore();//将输入流cin内的数据清空掉
    cout << "please input the string" << endl;
    cin.get(ptr, size+1);//C风格字符数组最后一个元素必须为\0
    cout << ptr << endl;
    delete [] ptr;//记得释放内存空间，否则会造成内存泄漏
    return 0;
}
