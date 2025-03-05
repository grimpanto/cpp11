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

    for (int x{2}; x < 3; ++x) {
        cout << "x in statement: " << x << endl;
    }

    cout << "local x (after assignment): " << x << endl;
}
