
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    auto values = {1, 2, 3, 4};
    int sum{};
    for_each(begin(values),
             end(values),
             [&sum](int val) { sum += val; });
    cout << sum << endl;
}
