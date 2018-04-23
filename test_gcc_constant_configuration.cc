#include <iostream>
#include <vector>

using namespace std;

int main()
{
    # if defined(_sgi)
        cout << "_sgi" << endl;
    # endif

    # if defined(_GNUC_)
        cout << "_GNUC_" << endl;
        cout << "_GNUC_" << ' ' << _GNUC_MINOR_ << endl;
   # endif

   #ifdef _STL_NO_DRAND48
        cout << "_STL_NO_DRAND48 defined" << endl;
   #else
        cout  << "_STL_NO_DRAND48 undefined" << endl;
   #endif

   #ifdef _STL_STATIC_TEMPLATE_MEMBER_BUG
        cout << "_STL_STATIC_TEMPLATE_MEMBER_BUG defined" << endl;
   #else
        cout << "_STL_STATIC_TEMPLATE_MEMBER_BUG undefined" << endl;
   #endif

   #ifdef _STL_CLASS_PARTIAL_SPECIALIZATION
        cout << "_STL_CLASS_PARTIAL_SPECIALIZATION defined" << endl;
   #else
        cout << "_STL_CLASS_PARTIAL_SPECIALIZATION undefined" << endl;
   #endif
   
   return 0;

}
