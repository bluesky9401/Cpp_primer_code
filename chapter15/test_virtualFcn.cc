#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class Base {
public:
    Base() = default;
    Base(const string &info): information_(info) { }
    virtual void printInfo() const { cout << information_ << endl; }
protected:
    string information_;
};

class PulBase : public Base {
public:
    PulBase() = default;
    PulBase(const string &info): Base(info) { }
    void printInfo(int i) const { cout << i;}
};

int main()
{
    Base item1(string("chentongjie"));
    PulBase item2(string("huazhou"));
    Base *item = &item2;
    item1.printInfo();
    item->printInfo();
}
