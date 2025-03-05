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

    const int months{12};
    constexpr int days_per_month{30};
    constexpr int days_per_year{months * days_per_month};
    cout << "Ein Bankenjahr hat " << days_per_year << " Tage" << endl;
}
