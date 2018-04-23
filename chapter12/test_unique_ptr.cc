#include <memory>
#include <iostream>
int main()
{
   int nvalue = 10;
   int *nptr = &nvalue;
   std::unique_ptr<int> uniptr(new int(12));
   std::cout << *uniptr << std::endl;
   return 0; 
}
