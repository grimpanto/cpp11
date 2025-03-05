#include <iostream>

using namespace std;

int main() {
    int i{1};
    int* p{&i};

    cout << "p == " << p << ", *p == " << *p << ", i == " << i << endl;
}
