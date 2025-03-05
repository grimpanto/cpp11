
#include <iostream>

using namespace std;

const double pi{atan(1) * 4};
constexpr double perimeter_unit_circle{2 * pi};

static_assert(false, "" + perimeter_unit_circle);

int main() {
    int i{1};
    auto& j = i;
    j = 2;
    cout << i << endl;
}
