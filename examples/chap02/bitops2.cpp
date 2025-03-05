#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

int main() {

    unsigned int u1{0x0F};
    unsigned int u2{0x3C};

    cout << "u1 = " << bitset<8>{u1} << endl;
    cout << "u2 = " << bitset<8>{u2} << endl;
    cout << "u1 | u2 = " << bitset<8>{u1 | u2} << endl;
    cout << "u1 & u2 = " << bitset<8>{u1 & u2} << endl;
    cout << "u1 ^ u2 = " << bitset<8>{u1 ^ u2} << endl;
    cout << "~u1 = " << bitset<8>{~u1} << endl;

    if (u1 & 0x07 == 1) {
        cout << "Bit 0 oder 1 oder 2 von u1 ist gesetzt!";
    } else {
        cout << "Weder Bit 0 noch 1 noch 2 von u1 ist nicht gesetzt!";
    }
}
