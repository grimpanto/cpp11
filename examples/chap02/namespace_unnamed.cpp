#include <iostream>
#include <vector>

using namespace std;

namespace {
    int sum;
    void count(vector<int> v) {
        for (auto i : v)
            sum += i;
    }
}

int main() {
    count({1, 2, 3, 4, 5});
    cout << sum << endl;
}
