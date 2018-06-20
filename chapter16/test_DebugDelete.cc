#include "DebugDelete.h"
#include <memory>
using std::unique_ptr;

int main()
{
    DebugDelete deleter;
    unique_ptr<int, DebugDelete> ptr(new int, deleter); 
    return 0;
}
