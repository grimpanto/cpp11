
#include <iostream>

using namespace std;

int main() {
    auto f = [x = 1]() { return x; };
    cout << f() << endl;
}
