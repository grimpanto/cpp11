#include <iostream>

using namespace std;

int f() {
    cout << "f()" << endl;
    return 1;
}

int g() {
    cout << "g()" << endl;
    return 2;
}

int h() {
    cout << "h()" << endl;
    return 3;    
}

int main() {
    int i{};

    i = f() + g() * h();
    ++i = i++;
    
}
