#include <iostream>
#include <algorithm>

namespace Estd {
    using namespace std;

    template <typename T>
    void sort(T& seq) {
        std::sort(begin(seq), end(seq));
    }
}

using namespace Estd;

int main() {
    int nums[]{3, 5, 2, 1, 4};

    sort(nums);

    for (auto n : nums) {
        cout << n << ' ';
    }
    cout << endl;
}
