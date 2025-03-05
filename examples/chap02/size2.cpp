#include <iostream>

using namespace std;

int main() {
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long long) << endl;

    static_assert(3 == sizeof(int), "Größe eines ints hat nicht 3 Bytes");
}
