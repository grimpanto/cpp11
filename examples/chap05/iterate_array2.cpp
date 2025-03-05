
#include <iostream>

using namespace std;

int main() {
    int coords[3]{1};

    for (int i{0}; i < sizeof(coords) / sizeof(int); ++i) {
        cout << coords[i] << endl;
    }

    cout << endl;
    
    for (auto i : coords) {
        cout << i << endl;
    }
}
