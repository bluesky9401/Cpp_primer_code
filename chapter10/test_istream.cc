#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

int main()
{
    std::istream_iterator<int> in(std::cin), eof;
    std::cout << accumulate(in, eof, 0) << std::endl;
}
