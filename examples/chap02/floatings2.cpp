#include <iostream>

using namespace std;

int main() {
    float f{1.5};
    double d{1.5};
    long double ld{1.5};
    
    cout << sizeof(f + f) << endl;
    cout << sizeof(d + d) << endl;
    cout << sizeof(ld + ld) << endl;

    cout << sizeof(f + d) << endl;
    cout << sizeof(ld + d) << endl;
}
