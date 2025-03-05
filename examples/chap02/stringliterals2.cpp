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
}
