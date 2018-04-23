#include <iostream>
#include <functional>

int func(int lhs, int rhs)
{
    return lhs * rhs;
}

auto lambda_object = [] (int lhs, int rhs) {
                      return lhs * rhs;};
class MyClass{
  public:
    int operator()(int lhs, int rhs) const
    {
        return lhs * rhs;
    }

    int m_func(int lhs, int rhs)
    {
        return lhs *rhs;
    }
};

int main()
{
    MyClass c;
    int value1 = std::bind(func, 4, 5)();
    int value2 = std::bind(lambda_object, 4, 5)();
    int value3 = std::bind(MyClass(),4, 5)();
    int value4 = std::bind(&MyClass::m_func, c, 4, 5)();
    std::cout << "value1 = " << value1
              << "value2 = " << value2
              << "value3 = " << value3
              << "value4 = " << value4
              << std::endl;
    return 0;
}
