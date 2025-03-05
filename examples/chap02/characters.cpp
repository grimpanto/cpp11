#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "char hat Vorzeichen: " << boolalpha << numeric_limits<char>::is_signed
         << endl;
}
