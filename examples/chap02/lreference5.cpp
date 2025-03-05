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

    /*
    int* q{nullptr};
    int& r1{0};
    int& r2{q};
    */

    {
        const int& r{1};
        cout << r << endl;
    }

    string long_names[]{"maxi", "mini", "otto"};

    for (const auto& name : long_names) {
        cout << name << endl;
    }
}
