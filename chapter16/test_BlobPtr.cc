#include "Blob.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Blob<string> strBlob = {"chen","tong","jie","ni","hao"};
    BlobPtr<string> ptr(strBlob, 1);
    cout << *ptr << endl;
}
