#include <iostream>
#include <string>
using std::cout;
using std::endl;
template<typename Arr>
void print(Arr const &arrValue)
{
    for(auto const &element: arrValue){
        cout << element << endl;
    }
}

int main()
{
    int sz_nValue1[] = {1,2,3};
    std::string sz_strValue2[] = {"wo","chen"};
    print(sz_nValue1);
    print(sz_strValue2);
    return 0;
}
