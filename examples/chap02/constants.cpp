#include <iostream>

using namespace std;

int main() {
    int min;
    int size;

    cout << "Minimum: ";
    cin >> min;
    cout << "Größe: ";
    cin >> size;

    const int max{min + size};
    cout << "Maximum = " << max << endl;
    //max = 3;
}
