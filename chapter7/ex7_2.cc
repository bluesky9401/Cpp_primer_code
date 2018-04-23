#include <iostream>
#include "SalesData.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    SalesData total;//save the current add result of total
    if (read(cin, total)){
        SalesData trans;
        while (read(cin, trans)){
            if (total.isbn() == trans.isbn()){
                total.combine(trans); //refresh the current total
            }else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }else{
        std::cerr << "No Data?!" << endl;
    }
    return 0;
}
