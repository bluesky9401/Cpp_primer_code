#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;
using std::istringstream;
using std::string;
using std::map;
using std::set;

int main(int n, char *argv[])
{
    typedef vector<string>::size_type line_no;
    ifstream ifs(argv[1]);
    vector<string> text;
    string line;
    string word;
    line_no curr_line_number;
    map<string, set<line_no>> map_word_to_line;

    // 存放文本数据以及制作文本中word与行数的映射表
    while (ifs >> line) {
        text.push_back(line);
        curr_line_number = text.size();
        istringstream istrs(line);
        while (istrs >> word) {
            auto &set_line = map_word_to_line[word];
            set_line.insert(curr_line_number);
        }      
    }
    
    string answer;
    // 用户交互过程
    while (1) {
        cout << "please enter the word you want to sought "
             << "or if you want to quit,please enter q! " << endl;
        if (!(cin >> answer) || answer == "q") {
            cout << "process stop! " << endl;
            break;
        }
            auto iter_pair_result = map_word_to_line.find(answer);
        if (iter_pair_result == map_word_to_line.end()){
            cout << "no data in the text" << endl;
        } else {
            auto &set_line = iter_pair_result->second;
            cout << "the word " << answer << " occurs " 
                 << set_line.size() << " times" << endl;
            for(auto &element: set_line) {
                cout << "\t(line " << element << ") ";
                cout << *(text.begin() + element -1)
                     << endl;
            }
        }    
        
    }
}
