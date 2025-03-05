
namespace MathUtils {
    double sum(double op1, double op2) {
        return op1 + op2;
    }
}

#include <iostream>

using namespace std;

int main() {
    double sum;
    // sum = sum(1, 2);
    // sum = ::sum(1, 2);
    sum = MathUtils::sum(1, 2);
    cout << sum << endl;
}
