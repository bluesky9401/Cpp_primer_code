#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;
#include <map>
using std::map;
#include <string>
using std::string;
#include <stdexcept>
using std::runtime_error;

void wordTransform(ifstream &map_file, ifstream &text);
map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &word, map<string, string> &trans_rule);

int main()
{
    ifstream map_file("mapFile.txt");
    ifstream text("text.txt");
    cout << "start to transform..." << endl;
    wordTransform(map_file, text);
    cout << "transform completed!" << endl;
    return 0;
}

void wordTransform(ifstream &map_file, ifstream &text)
{
    auto trans_rule = buildMap(map_file);
    string line;

    while (getline(text, line)) {
        istringstream isstream(line);
        string word;
        bool is_first_word = true;
        while (isstream >> word) {

            if (is_first_word)
                is_first_word = false;
            else
                cout << " " ;

            cout << transform(word, trans_rule);
        }
        cout << endl;
    }
}

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_rule;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_rule[key] = value.substr(1);
        else
            throw runtime_error("no rule for" + key);
    }
    return trans_rule;
}

const string &transform(const string &word, map<string, string> &trans_rule)
{
    auto map_it = trans_rule.find(word);
    if (map_it != trans_rule.cend())
        return map_it->second;
    else
        return word;
}
