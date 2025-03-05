#include <iostream>

using namespace std;

int main() {
    const char* alphabet;
    alphabet = "abcdefghijklmnopqrstuvwxyz\n"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << alphabet << endl;

    alphabet = R"(abcdefghijklmnopqrstuvwxyz"\n
ABCDEFGHIJKLMNOPQRSTUVWXYZ)";
    cout << endl << alphabet << endl;

    alphabet = R"=(abcdefghijklmnopqrstuvwxyz)"\n
ABCDEFGHIJKLMNOPQRSTUVWXYZ)=";
    cout << endl << alphabet << endl;

    cout << u8"Müßiggang" << endl;
    cout << u8"M\xc3\xbcßiggang" << endl;
}
