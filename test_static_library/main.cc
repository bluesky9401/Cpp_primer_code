#include <iostream>
#include "operateVector.h"

int x[2] = {1,3};
int y[2] = {2,4};
int z[2];
int main()
{
    addVec(x,y,z,2);
    mulVec(x,y,z,2);
    return 0;
}
