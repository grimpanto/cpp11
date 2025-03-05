
#include <iostream>

using namespace std;

void print(const char* names[], int size) {
    for (int i{}; i < size; ++i) {
        cout << names[i] << endl;
    }
}

int main() {
    const char* names[5] {"otto", "ulli", "susi"};
    cout << sizeof(names) << endl;

    for (int i{}; i < sizeof(names) / sizeof(const char*); ++i) {
        cout << names[i] << endl;
    }

    cout.clear();
    cout << "Hello!" << endl;

    for (auto n : names) {
        if (n)
            cout << n << endl;
    }

    print(names, 3);
}
