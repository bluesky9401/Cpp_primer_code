#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

std::string::size_type biggerThan6(const std::vector<std::string> strvec_sentence)
{
    return std::count_if(strvec_sentence.begin(), strvec_sentence.cend(),
                    [] (const std::string &word) {return word.size() > 6;});
}

int main()
{
   std::vector<std::string> strvec_sentence = {"chen", "tongjie", "zhende", "haoshuaia"};
   std::cout << biggerThan6(strvec_sentence)
              << std::endl;
   return 0; 
}
