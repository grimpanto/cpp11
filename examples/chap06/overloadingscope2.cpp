
#include <iostream>

using namespace std;

int incr(int counter) {
    cout << "int" << endl;
    return counter + 1;
}

int incr(double counter) {
    cout << "double" << endl;
    return counter + 1;
}

int main() {
    int incr(double counter);

    incr(1);
}
