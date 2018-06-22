#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <regex>
using std::regex;
using std::smatch;
#include <string>
using std::string;

int main()
{
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results;
    string file_name;
    while (cin >> file_name)
        if (regex_search(file_name, results, r))
            cout << results.str() << endl;
    return 0;
}
