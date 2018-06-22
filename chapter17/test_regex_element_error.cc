#include <iostream>
using std::cout;
using std::endl;
#include <regex>
using std::regex;
#include <string>
using std::wstring;
int main()
{
    regex r1("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    std::smatch results;
    wstring str(10, wchar_t('w'));
    if (regex_search(str, results, r1))
        cout << results.str() << endl;
    return 0;
}
