
#include <iostream>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double mul(double a, double b) {
    return a * b;
}

int main() {
    double (*f)(double, double);

    f = add;
    cout << f(3, 2) << endl;
    f = mul;
    cout << f(3, 2) << endl;
}
