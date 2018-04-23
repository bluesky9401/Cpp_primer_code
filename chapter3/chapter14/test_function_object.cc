#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class PrintString{
public:
    PrintString(std::ostream &os = cout, char cSeparate = ' '): m_os(os), m_cSeparate(cSeparate) { }
    void operator()(const string &strValue) const { m_os << strValue << m_cSeparate;}
private:
    std::ostream &m_os;
    char m_cSeparate;
};

int main()
{
    PrintString printer;
    string strValue;
    cout << "Please input a series of string: "<< endl;
    cin >> strValue;
    printer(strValue);
    return 0;
}
