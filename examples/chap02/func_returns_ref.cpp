
#include <iostream>

using namespace std;

int& g() {
    int i;
    return i;
}

int main() {
    cout << g() << endl;
    g() = 1;
}
