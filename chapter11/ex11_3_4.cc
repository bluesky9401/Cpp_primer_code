#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using MapWordCount = std::map<std::string, std::size_t>;

auto count_word()
{   
    MapWordCount counts;  
    for(std::string word; cin >> word; ++counts[word]);
    return counts;
}

auto strip_word(std::string &word) -> const std::string&
{
    for(auto &element: word)
    {
        element = tolower(element);
    }
    word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
    return word;
}

auto stripAndCountWord()
{
    MapWordCount counts;
    for(std::string word; cin >> word; ++counts[strip_word(word)]);
    return counts;
}

void print(const MapWordCount &counts)
{
    for(auto &element: counts)
        cout << element.first << " occurs " << element.second << " times\n";
}

int main()
{
    cout << "please enter a few words" << endl;
    print(count_word());
    cin.clear();
    cout << "please enter a few words" << endl;
    print(stripAndCountWord());
    return 0;
}
