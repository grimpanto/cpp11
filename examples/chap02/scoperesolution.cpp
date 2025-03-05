#include <iostream>

using namespace std;

double sum(double op1, double op2) {
    return op1 + op2;
}

int main() {
    double sum;
    //sum = sum(1, 2);
    sum = ::sum(1, 2);
    cout << sum << endl;
}
