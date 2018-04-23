#include <memory>
using std::allocator;
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;

int main(int argc, char *argv[])
{
    int n = 4;
    ifstream ifs(argv[1]);
    string word;
    allocator<string> alloc;
    auto ptr = alloc.allocate(n);
    auto ptr_curr_next = ptr;
    while (n--) {
        ifs >> word;
        alloc.construct(ptr_curr_next++, word); 
        cout << word << endl;       
    }
    while (ptr != ptr_curr_next) {
        alloc.destroy(--ptr_curr_next);
    }
    alloc.deallocate(ptr, 3);
    return 0;
}
