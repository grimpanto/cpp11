#include <iostream>

using namespace std;

int main() {
    bool a{};
    bool b{};

    cin >> boolalpha;
    
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    
    cout << boolalpha;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    bool c{};
    c = a + b;
    cout << "a + b = " << c << endl;
    c = a - b;
    cout << "a - b = " << c << endl;
    c = a && b;
    cout << "a && b = " << c << endl;
}
