#include "Blob.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Blob<int> data{1, 2, 3, 6};
    Blob<int>::size_type size = data.size();
    decltype(size) i = 0;
    for(i = 0; i != size; i++) {
        cout << data[i] << " " << endl;
    }
    return 0;
}
