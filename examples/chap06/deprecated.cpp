
#include <iostream>

using namespace std;

[[deprecated]]
int x{1};

[[deprecated]]
int f(int x) {
    return x;
}

int main() {
    cout << f(x) << endl;
}
