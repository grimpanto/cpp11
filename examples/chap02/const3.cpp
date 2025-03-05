#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double pi{atan(1)*4};
    const double e{exp(1)};

    //    double* p;
    const double* p;
    p = &pi;
    p = &e;

    double d1{1};
    double d2{2};
    /*
    double* const q;
    q = &pi;
    */
    double* const q{&d1};
    *q = 2;
    cout << d1 << endl;
}
