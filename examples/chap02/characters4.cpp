#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "char hat Vorzeichen: " << boolalpha << numeric_limits<char>::is_signed
         << endl;

    cout << "char hat Vorzeichen: " << boolalpha << numeric_limits<char>::digits
         << endl;

    for (int i{0}; i < 10; ++i) {
        cout << static_cast<char>('0' + i) << endl;
    }
}
