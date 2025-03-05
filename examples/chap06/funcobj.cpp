
#include <iostream>
#include <functional>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double mul(double a, double b) {
    return a * b;
}

int main() {
    std::function<double(double, double)> f;
    f = add;
    cout << f(3, 2) << endl;
}
