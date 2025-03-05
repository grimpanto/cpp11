
#include <iostream>

using namespace std;

void print(char* names[10]) {
    cout << sizeof(names) << endl;
}

int main() {
    char* names[5];
    print(names);
}
