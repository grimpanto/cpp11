
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    string name{"Bob"};
    //auto f = [name]() { name = ""; };
    auto f = [name]() mutable { name = ""; };
}
