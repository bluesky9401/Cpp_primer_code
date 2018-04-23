#include <memory>
#include <vector>
#include <string>

using std::shared_ptr;
using std::vector;
using std::string;
using std::make_shared;

int main()
{
    shared_ptr<vector<string>> ptr_strvec = make_shared<vector<string>>();

   { auto &ref_ptr_strvec = ptr_strvec;
      int i = 0;
   }
   return 0;
}
