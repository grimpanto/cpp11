
#include <iostream>

using namespace std;

auto sum(int a, int b) -> decltype(a + b) {
    return a + b;
}

int main() {
    cout << "Die Summe von 3 und 5 ist " << sum(3,5) << endl;
}
