#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main()
{
    std::ifstream input("chentongjie_information.md");
    std::string strvalue;
    std::vector<std::string> vec_strvalue;
    while (input >> strvalue){
        vec_strvalue.push_back(strvalue);
    }
    for(auto &element: vec_strvalue){
        std::cout << element << std::endl;
    }
    return 0;
}
