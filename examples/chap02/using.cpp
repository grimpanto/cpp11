#include <iostream>
#include <vector>

int main() {
    using IntStack = std::vector<int>;
    
    IntStack stack{};
    
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);

    std::cout << "top: " << stack.back() << std::endl;
    stack.pop_back();
    std::cout << stack.back() << std::endl;
    stack.pop_back();
    std::cout << "bottom: " << stack.back() << std::endl;
    stack.pop_back();
}
