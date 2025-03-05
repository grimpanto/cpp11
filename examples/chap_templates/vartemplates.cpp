
#include <iostream>

using namespace std;

template <typename T>
constexpr T pi = T{3.1415926535897932385};

template <typename T>
T circle_perimeter(T r) {
    return 2 * r * pi<T>;
}

int main() {
    cout << circle_perimeter(2.5) << endl;
}
