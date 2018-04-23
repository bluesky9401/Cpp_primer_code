#include <iostream>
#include <vector>
#include <iterator>
#include <list>
namespace ch16
{
template<typename Iterator, typename Value> 
auto find(Iterator first, Iterator last, const Value &value)
{
    for(;first != last && *first != value; first++){
        ;
    }
    return first;
}
}
int main()
{
    std::vector<int> vec_nValue{1, 3, 5, 6,10};
    std::list<std::string> lst_strValue{"chen","tong","jie"};
    auto is_in_vec = vec_nValue.cend() != ch16::find(vec_nValue.cbegin(),vec_nValue.cend(),3);//notice realize the code from right to left:
    std::cout << (is_in_vec ? "found":"not found") << std::endl;
}
