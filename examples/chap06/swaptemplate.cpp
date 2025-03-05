
#include <iostream>
#include <memory>

template <typename T>
void swap(T& a, T& b) {
    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}


int main() {
    int i1{1};
    int i2{2};

    swap(i1, i2);
    std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
}
