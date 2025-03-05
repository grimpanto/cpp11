
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

    auto f2 = std::bind(f, 3, 2);
    cout << f2() << endl;

    using namespace std::placeholders;  // _1, _2,...
    auto f3 = std::bind(f, _1, 2);
    cout << f3(3) << endl;
}
