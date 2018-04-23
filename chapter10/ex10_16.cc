#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

void elimDups(std::vector<std::string> &strvecSentences)
{
    std::sort(strvecSentences.begin(), strvecSentences.end());//sort the input sentences
    auto iterNewEnd = std::unique(strvecSentences.begin(), strvecSentences.end());
    strvecSentences.erase(iterNewEnd, strvecSentences.end());
}

void biggies(std::vector<std::string> &strvecSentences, std::vector<std::string>::size_type sz)
{
    elimDups(strvecSentences);//delete the duplication words

    // sort the sentences by the length,but maintain the alphabetical if the size is same
    std::stable_sort(strvecSentences.begin(), strvecSentences.end(),
                    [] (const std::string &lhs, const std::string &rhs) {return lhs.size() < rhs.size();});

    auto iterSizeBiggerSz = std::find_if(strvecSentences.begin(), strvecSentences.end(),
                        [sz] (const std::string &strWord) {return strWord.size() >= sz;});

    std::for_each(iterSizeBiggerSz, strvecSentences.end(), 
                    [] (const std::string &strWord) {cout << strWord << " ";}); 
}

int main()
{
    std::vector<std::string> strvecSentences{"chen","tong","jie","nv","li","ping","bo","chennn","tong"};
    biggies(strvecSentences, 3);
    cout << endl;
}
