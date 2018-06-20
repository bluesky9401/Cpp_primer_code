#include <iostream>

int main()
{
    int *nval = new int(1024);
    int &refVal = *nval;
    std::cout << refVal << std::endl;
    delete nval;
    std::cout << refVal << std::endl;
    return 0;
}
