#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
int main()
{
    ifstream input("test.txt");
    string strvalue;
    if (input){
        vector<string> vec_strvalue;
        while (getline(input, strvalue)){
            vec_strvalue.push_back(strvalue);
        }
        input.close();
        ofstream output("test.txt");
        output.close();
        for(auto &element: vec_strvalue){
            std::cout << element << std::endl;
        }
    } else {
        cout << "open file fali!" << endl;
    }
    return 0;
}
