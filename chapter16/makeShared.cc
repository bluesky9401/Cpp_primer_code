#include <memory>
#include <utility>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

template <typename T, typename... Args>
auto makeShared(Args&&... args) -> std::shared_ptr<T>
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    auto ptr = makeShared<string>("chentongjie");
    cout << *ptr << endl;
    return 0;
}
