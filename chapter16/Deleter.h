#ifndef _DELETER_H_
#define _DELETER_H_
#include <iostream>

class Deleter { 
public:
    Deleter(std::ostream &os = std::cerr): os_(os) { }
    template <typename T> void operator() (T *p) const
    { delete p;}
};
#endif
