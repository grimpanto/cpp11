#include <iostream>

using namespace std;

double squared(double);
void print(string msg);
int one();

int main() {
    print("2^2 - 1 = ");
    cout << squared(2) - one() << endl;

    double val{5};
    cout << squared(val) << endl;
    cout << val << endl;
}

double squared(double val) {
    val = val * val;
    return val;
}

void print(string message) {
    cout << message;
}

int one() {
    return 1;
}

