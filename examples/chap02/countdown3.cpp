#include <iostream>

using namespace std;

int main() {
    cout << "Startwert: ";
    int cnt{};
    cin >> cnt;

    if (cnt)
        cout << cnt << endl;

    while (1 != 2) {
        if (cnt <= 1)
            break;
        --cnt;
        if (cnt > 5 && cnt % 2)
            continue;
        cout << cnt << endl;
    }
}
