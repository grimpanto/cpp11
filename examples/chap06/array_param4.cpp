
#include <iostream>

using namespace std;

void print(const char* names[10]) {
    cout << sizeof(names) << endl;
}

int main() {
    const char* names[5] {"otto", "ulli", "susi"};
    cout << sizeof(names) << endl;

    for (int i{}; i < sizeof(names) / sizeof(const char*); ++i)
        cout << names[i] << endl;
}
