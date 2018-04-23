#include <vector>
#include <string>
int main()
{
    class MyClass;
    typedef std::vector<MyClass>::size_type vec_my_class_size_type;
    
}
class MyClass{
public:
        std::string m_name;
        MyClass() = default;
        MyClass(std::string strname):m_name(strname) { }
};
