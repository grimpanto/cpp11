#include <iostream>

using namespace std;

int main() {
    char a{'0'};
    char b{'0'};

    cout << "a = " << a << "; sizeof(a) = " << sizeof(a) << endl;
    cout << "b = " << b << "; sizeof(b) = " << sizeof(b) << endl;
    cout << "a + b = " << a + b << "; sizeof(a + b) = " << sizeof(a + b) << endl;
}
