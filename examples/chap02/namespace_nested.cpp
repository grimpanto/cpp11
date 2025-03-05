#include <iostream>

using namespace std;

namespace MathUtils {
    namespace Arithmetic {
        double sum(double op1, double op2) {
            return op1 + op2;
        }
    }
}

int main() {
    cout << MathUtils::Arithmetic::sum(1, 2) << endl;
}
