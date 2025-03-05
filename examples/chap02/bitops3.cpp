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
        cout << "Bit 0 oder 1 oder 2 von u1 ist gesetzt!" << endl;
    } else {
        cout << "Weder Bit 0 noch 1 noch 2 von u1 ist nicht gesetzt!" << endl;;
    }
    
    cout << "u1 << 2 = " << bitset<8>{u1 << 2} << endl;
    cout << "u1 << 3 = " << bitset<8>{u1 << 3} << endl;
    cout << "u1 >> 3 = " << bitset<8>{u1 >> 2} << endl;
    
    int8_t i1{-127};
    cout << "i1 = " << static_cast<int>(i1) << " = " << bitset<8>{static_cast<uint8_t>(i1)} << endl;
    cout << "i1 >> 2 = " << bitset<8>{static_cast<uint8_t>(i1 >> 2)} << endl;
}
