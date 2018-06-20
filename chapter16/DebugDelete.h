#ifndef _DEBUGDELETE_H_
#define _DEBUGDELETE_H_
#include <iostream>

class DebugDelete { 
public:
    DebugDelete(std::ostream &os = std::cerr): os_(os) { }
    template <typename T> void operator() (T *p) const
    { os_ << "deleting unique_ptr" << std::endl; delete p;}
private:
    std::ostream &os_;
};
#endif
