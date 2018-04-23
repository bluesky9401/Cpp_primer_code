#include <fstream>
#include <iostream>
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    std::ifstream ifs("chentongjie.txt");
    TextQuery text(ifs);
    std::string response;
    while (1) {
        cout << "please enter the word you want to find. "
             <<  "if you want to quit, please enter q."
             << endl;
         
        if (!(cin >> response) || response == "q") {
            cout << "the process stop. " << endl;
            break;
        }
        QueryResult result = text.query(response);
        print(cout, result);
    }
    return 0;
}
