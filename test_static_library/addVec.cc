#include "operateVector.h"
int addcnt = 0;
void addVec(int *x, int *y, int *z, int n)
{
    int i = 0;
    ++addcnt;
    for(int i = 0; i < n; i++)
    {
        z[i] = x[i] + y[i];
    }
}
