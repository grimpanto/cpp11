#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main() {
    using IntStack = std::vector<int>;
    
    IntStack stack{};
    
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);

    cout << "top: " << stack.back() << endl;
    stack.pop_back();
    cout << stack.back() << endl;
    stack.pop_back();
    cout << "bottom: " << stack.back() << endl;
    stack.pop_back();
}
