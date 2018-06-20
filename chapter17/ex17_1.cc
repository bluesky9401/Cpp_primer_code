#include <tuple>
using std::tuple;
using std::tuple_size;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    tuple<int, int, int> threeInt{10, 20, 30};
    auto size = tuple_size<decltype(threeInt)>::value;
        cout << std::get<0>(threeInt) << endl;
    return 0;
}
