
#include <iostream>
#include <functional>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double mul(double a, double b) {
    return a * b;
}

double volume_cuboid(double a, double b, double c) {
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    return a * b * c;
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

    auto f4 = std::bind(volume_cuboid, _2, 2, _1);
    f4(3, 4);
}
