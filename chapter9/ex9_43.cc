#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    for (auto cur = s.begin(); cur <= s.end()-oldVal.size(); )
        if (oldVal == string(cur, cur+oldVal.size())) {
            cur = s.erase(cur, cur+oldVal.size());
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size();
        } else {
            ++ cur;
        }
}

int main()
{
    string str{"though chen tong jie has done something wrong, but he is just heart! "};
    replace_string(str, "though", "tho");
    cout << str << endl;
    return 0;
}
