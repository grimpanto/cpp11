#include <iostream>
#include <vector>

using namespace std;

namespace MathUtils {
    class IntVector {};
    int size(IntVector, int) {
        return 1;
    }
}

namespace GameEngine {
    MathUtils::IntVector v;

    int size(MathUtils::IntVector, unsigned) {
        return 2;
    }

    int calculate() {
        return size(v, 10);
    }
}

int main() {
    cout << GameEngine::calculate() << endl;
}
