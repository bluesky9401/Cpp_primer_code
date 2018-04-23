#include <iostream>
#include <regex>
int main()
{
    std::string strpattern("[^c]ei");
    strpattern = "[[:alpha:]]*" + strpattern + "[[:alpha:]]*";
    std::regex r(strpattern);
    std::smatch results;
    std::string test_str = "receipt freind theif receive";
    if (std::regex_search(test_str, results, r))
            std::cout << results.str() << std::endl;
    return 0;
}
