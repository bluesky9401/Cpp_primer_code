#include <iostream>

template <typename T> 
class MyClass{
  private:
         T value;
  public:
        template <typename X>
        void assign(const MyClass<X> &x)
        {
            value = x.getValue();
        } 
        T getValue() const
        {
            return value;
        }
};

int main()
{
    MyClass<int> n_my_class;
    MyClass<double> d_my_class1;
    MyClass<double> d_my_class2;
    d_my_class1.assign(n_my_class);
    d_my_class1.assign(d_my_class2);
    return 0;

}
