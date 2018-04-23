#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> nvec_value1 = {1,2,3,4};
    std::vector<int> nvec_value2 = {2,3,4,5};
    auto pt_value1 = &nvec_value1[0];
    auto pt_value2 = &nvec_value2[0];
    swap(nvec_value1, nvec_value2);
    auto pt_value1_swap = &nvec_value1[0];
    auto pt_value2_swap = &nvec_value2[0];
    std::cout << "before swap:\n" << "the value1 pointer:" << pt_value1
              << "before swap:\n" << "the value2 pointer:" << pt_value2
              << "after swap:\n" << "the value1 pointer:" << pt_value1_swap
              << "after swap:\n" << "the value1 pointer:" << pt_value2_swap 
              << std::endl;
}

