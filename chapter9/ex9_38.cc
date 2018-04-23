#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::vector<std::string> strvec_buffer;
    for (std::string buffer; cin >> buffer; strvec_buffer.push_back(buffer)) {
        cout << strvec_buffer.capacity() << ' ';
    }
    cout << endl;
    return 0;
}
