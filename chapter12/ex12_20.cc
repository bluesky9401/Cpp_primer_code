#include <iostream>
#include <string>
#include <fstream>
#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    StrBlob save_string;//逐行保存文件中的字符串
    std::ifstream fis("chentongjie.txt");
    for(std::string line; getline(fis, line); save_string.push_back(line));

    for(StrBlobPtr pbeg(save_string.begin()), pend(save_string.end()); pbeg != pend; pbeg.incr()){
        cout << pbeg.deref() << endl;
    }
    return 0;
}
