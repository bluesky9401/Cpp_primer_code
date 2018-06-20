#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iterator>
#include <algorithm>

void elimDups(vector<string> &data);
bool isShorter(const string &lhs, const string &rhs);

int main(int argc, char *argv[])
{
    ifstream ifs(argv[1]);
    vector<string> data;
    string word;

    while (ifs >> word) {
        data.push_back(word);
    }

    elimDups(data);
    std::stable_sort(data.begin(), data.end(), isShorter);

    for (auto &elem : data) 
        cout << elem << " ";
    cout << endl;

    return 0;
}

void elimDups(vector<string> &data)
{
    std::sort(data.begin(), data.end());
    auto end_unique = std::unique(data.begin(), data.end());
    data.erase(end_unique, data.end());
}

bool isShorter(const string &lhs, const string &rhs)
{
   return lhs.size() < rhs.size(); 
}
