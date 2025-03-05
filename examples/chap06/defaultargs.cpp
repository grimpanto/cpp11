
#include <iostream>

using namespace std;

int incr(int=0);

int incr(int counter) {
    return counter + 1;
}

int main() {
    cout << incr() << endl;
    cout << incr(1) << endl;
}
