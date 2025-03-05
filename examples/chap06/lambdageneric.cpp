
#include <iostream>

using namespace std;

int main() {
    auto f = [](auto x) { return x; };
    cout << f(1) << endl;
    cout << f("abc") << endl;
    cout << f(false) << endl;
}
