#include "operateVector.h"
int mulcnt = 0;
void mulVec(int *x, int *y, int *z, int n)
{
    int i = 0;
    ++mulcnt;
    for(int i = 0; i < n; i++)
    {
        z[i] = x[i] * y[i];
    }
}
