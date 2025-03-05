#include <iostream>

using namespace std;

int x;

int main() {
    cout << "global x: " << x << endl;
    
    int x;

    cout << "local x: " << x << endl;
}
