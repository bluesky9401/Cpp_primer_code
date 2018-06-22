#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <regex>
using std::regex;
using std::sregex_iterator;
#include <string>
using std::string;
#include <iterator>

int main()
{
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    string file;
    string str;
    
    while (ifs >> str)
        file = file + str + " ";

    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);

    for (sregex_iterator it(file.begin(), file.end(), r), end_it;
            it != end_it; ++it) {
        auto pos = it->prefix().length();
        pos = pos > 10 ? pos-10 : 0;
        ofs << it->prefix().str().substr(pos) 
            << "\n\t\t>>>" << it->str() << " <<<\n " 
            << it->suffix().str().substr(0, 10)
            << endl;
    }

    return 0;
}
