#include <iostream>

using namespace std;

int main() {
    int i{1};
    int res{};

    res = i++, i /= 2, i + 2;
    cout << res << endl;
}
