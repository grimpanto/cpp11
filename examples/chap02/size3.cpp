#include <iostream>

using namespace std;

int main() {
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long long) << endl;

    static_assert(4 <= sizeof(int), "int hat nicht mindestens 4 Bytes");
}
