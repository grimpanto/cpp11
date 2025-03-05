
#include <iostream>

using namespace std;

int nextid() {
    static int lastid;

    return ++lastid;
}

int main() {
    for (int i{}; i < 3; ++i)
        cout << nextid() << endl;
}
