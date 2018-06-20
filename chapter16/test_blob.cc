#include "Blob.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main()
{
    
    vector<string> strvec = {"chen", "tong", "jie"};
    Blob<string> nblob(strvec.begin(), strvec.end());
    std::size_t size = nblob.size();
    for(std::size_t i = 0; i != size; i++) {
        cout << nblob[i] << " " << endl;
    }
    return 0;
}
