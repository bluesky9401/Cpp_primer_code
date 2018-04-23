#include <list>
#include <iterator>
#include <iostream>
int main()
{
    std::list<int> nlst_value = {1, 2, 3, 4, 5};
    auto iter = nlst_value.begin();
    for (auto &element: nlst_value) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    while (iter != nlst_value.end()) {
        if (*iter % 2) {
            nlst_value.insert(iter, *iter);//double the odd and refresh the iterator
            std::advance(iter, 2);
        } else {
            iter = nlst_value.erase(iter);
        }
    }
    for (auto &element: nlst_value) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    return 0;
}
