#include <iostream>
#include <bitset>

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
}
