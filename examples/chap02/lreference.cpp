#include <iostream>

using namespace std;

int main() {
    int x{1};
    int& r{x};

    r = 2;
    cout << "x = " << x << endl;    
}
