#include <iostream>

using namespace std;

int i;

int& f() {
    cout << "f()" << endl;
    return i;
}

int main() {
    cout << "i == " << i << endl;
    f() = f() + 1;
    cout << "i == " << i << endl;
    f() += 1;
    cout << "i == " << i << endl;
    f()++;
    cout << "i == " << i << endl;
}
