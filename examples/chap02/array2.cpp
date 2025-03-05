#include <iostream>

using namespace std;

int main() {
    int* points{new int[10]};

    for (int i{0}; i < 10; ++i) {
        points[i] = i;
    }

    for (int i{0}; i < 10; ++i) {
        cout << *(points + i) << ' ';
    }

    cout << endl;

    delete[] points;
}
