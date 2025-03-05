#include <iostream>

using namespace std;

int main() {
    cout << "Startwert: ";
    int cnt{};
    cin >> cnt;

    if (cnt)
        cout << cnt << endl;

    while (cnt > 1) {
        --cnt;
        if (cnt > 5 && cnt % 2)
            continue;
        cout << cnt << endl;
    }
}
