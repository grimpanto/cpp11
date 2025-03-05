
#include <iostream>
#include <limits>

using namespace std;

constexpr int min(std::initializer_list<int> numbers) {
    int min = std::numeric_limits<int>::max();
    for (int n : numbers)
        if (n < min) min = n;
            return min;
}

int main() {
    constexpr int min_number = min({5, 1, 8, -3, 9});
    cout << min_number << endl;
}
