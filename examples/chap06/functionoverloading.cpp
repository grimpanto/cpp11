
#include <iostream>

using namespace std;

void sayHello(char c) {
    cout << "Hello " << c << "!" << endl;
}

void sayHello(const char* str) {
    cout << "Hello " << str << "!" << endl;
}

void sayHello(string str) {
    cout << "Hello " << str << "!" << endl;
}

int main() {
    sayHello('!');
    sayHello("World");
    string name{"Bob"};
    sayHello(name);
}
