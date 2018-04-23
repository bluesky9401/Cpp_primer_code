#include <iostream>
#include <vector>

using ptr = std::vector<int> *;
auto makeNvec()
{
    return new std::vector<int>;
}

auto readInput(std::istream &is, ptr nvec_ptr)
{
    int temp;
    std::cout << "please enter integer: ";
    while(is >> temp){
        nvec_ptr->push_back(temp);
    }
    return nvec_ptr;
}

auto output(std::ostream &os, ptr nvec_ptr) -> std::ostream &
{
    for(auto &element: *nvec_ptr){
        os << element << ' ';
    }
    os << std::endl;
    return os;
}

int main()
{
    ptr nvec_ptr = readInput(std::cin, makeNvec());
    output(std::cout, nvec_ptr);
    return 0;
}
