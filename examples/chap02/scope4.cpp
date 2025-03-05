#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x;

void func(int y) {
    cout << "x in func (global): " << x << endl;
    ++y;
    cout << "y in func (local): " << y << endl;
}


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

    int y{1};

    cout << "local y (before function call): " << y << endl;
    
    func(y);

    cout << "local y (after function call): " << y << endl;
}
