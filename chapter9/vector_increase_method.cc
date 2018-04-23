#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nvec;
    std::cout << "nvec: size: " << nvec.size() 
              << "nvec: capacity: " << nvec.capacity() << std::endl;
    // add 24 elements to nvec
    for (std::vector<int>::size_type size_i = 0; size_i != 24; ++ size_i) {
        nvec.push_back(size_i);
    }
    std::cout << "nvec: size: " << nvec.size() 
              << "nvec: capacity: " << nvec.capacity() << std::endl;
    nvec.reserve(50);
    std::cout << "nvec: size: " << nvec.size() 
              << "nvec: capacity: " << nvec.capacity() << std::endl;
    while (nvec.size() != nvec.capacity()) {
        nvec.push_back(0);
    }
    std::cout << "nvec: size: " << nvec.size() 
              << "nvec: capacity: " << nvec.capacity() << std::endl;
    nvec.push_back(50);
    std::cout << "nvec: size: " << nvec.size() 
              << "nvec: capacity: " << nvec.capacity() << std::endl;
    nvec.shrink_to_fit();
    std::cout << "nvec: size: " << nvec.size() 
              << "nvec: capacity: " << nvec.capacity() << std::endl;
    return 0;        
}
