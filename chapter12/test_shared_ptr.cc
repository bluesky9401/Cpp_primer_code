#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::make_shared;
int main()
{
    int *ptr_data = new int(12);

    auto sp = make_shared<int>(5);
    auto sp2 = sp;
    cout << "*sp = " << *sp << endl;

    sp.reset(ptr_data);
    cout << "*sp = " << *sp << endl;
    return 0;
}
