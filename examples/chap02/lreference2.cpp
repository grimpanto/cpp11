#include <iostream>

using namespace std;

int main() {
    int x{1};
    int& r{x};

    r = 2;
    cout << "x = " << x << endl;

    int* p{nullptr};
    p = &x;
    *p = 3;
    cout << "x = " << x << endl;
}
