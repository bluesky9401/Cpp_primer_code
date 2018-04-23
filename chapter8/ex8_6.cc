#include <fstream>
#include <iostream>
#include "SalesData.h"
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2], std::ofstream::app);
    SalesData total;//save the current add result of total
    if (read(input, total)){
        SalesData trans;
        while (read(input, trans)){
            if (total.isbn() == trans.isbn()){
                total.combine(trans); //refresh the current total
            }else{
                print(output, total);
                total = trans;
            }
        }
        print(output, total);
    }else{
        std::cerr << "No Data?!" << endl;
    }
    input.close();
    output.close();
    return 0;
}
