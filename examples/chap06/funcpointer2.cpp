
#include <iostream>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double mul(double a, double b) {
    return a * b;
}

using func = double (*)(double, double);

double accumulate(initializer_list<double> list, func f) {
    double res{};
    for (auto elem : list) {
        res = f(res, elem);
    }
    return res;
}

int main() {
    func f;

    f = add;
    cout << f(3, 2) << endl;
    f = mul;
    cout << f(3, 2) << endl;

    cout << accumulate({1.0, 2.0, 3.0, 4.0}, add) << endl;
}
