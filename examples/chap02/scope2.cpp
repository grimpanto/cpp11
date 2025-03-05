#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x;

int main() {
    cout << "global x: " << x << endl;
    
    int x;

    cout << "local x: " << x << endl;

    x = 1;
    
    {
        int x;
        cout << "x in block: " << x << endl;
    }

    cout << "local x (after block): " << x << endl;
}
