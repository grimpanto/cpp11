#include <iostream>

using namespace std;

int main() {
    int i{9};
    bool a{i != 0};
    bool b{true};
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    int c{};
    c = a + b;
    cout << "a + b = " << c << endl;
    c = a - b;
    cout << "a - b = " << c << endl;
    c = a && b;
    cout << "a && b = " << c << endl;
}
