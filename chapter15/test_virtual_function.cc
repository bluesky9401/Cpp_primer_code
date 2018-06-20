#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class Base {
public:
    Base(): str_("") { }
    Base(const string &s): str_(s) { }
    virtual void print() const
            { cout << str_ << endl; }
    virtual ~Base() = default;
private:
    string str_;
};

class Derived: public Base {
public:
    Derived() = default;
    Derived(const string &str1, const string &str2): Base(str1), str_der_(str2) { }
    virtual void print() const override
                { cout << str_der_ << endl; }
    ~Derived() = default;
private:
    string str_der_;
};

int main()
{
    Base base;
    base.print();
    Derived der("chen", "tong");
    Base &ref_base = der;
    ref_base.print();
    return 0;
}

