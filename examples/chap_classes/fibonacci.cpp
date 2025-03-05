
#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << "fib(1) = " << fib(1) << endl;
    cout << "fib(1) = " << fib(2) << endl;
    cout << "fib(1) = " << fib(3) << endl;
    cout << "fib(1) = " << fib(4) << endl;
    cout << "fib(1) = " << fib(5) << endl;
}
