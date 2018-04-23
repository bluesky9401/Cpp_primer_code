#include <functional>
#include <iostream>

std::function<int(int,int)> returnLambda()
{
    return [] (int x, int y){
            return x*y;
            };
}

int main()
{
    auto fun = returnLambda();
    std::cout << fun(4,3) << std::endl;
    return 0;
}
