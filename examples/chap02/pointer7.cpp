#include <iostream>

using namespace std;

int main() {
    int i{1};
    int* p{&i};

    cout << "p == " << p << ", *p == " << *p << ", i == " << i << endl;

    *p = 2;
    cout << "*p = 2;" << endl;
    cout << "p == " << p << ", *p == " << *p << ", i == " << i << endl;

    int j{};
    p = &j;
    cout << "p = &j;" << endl;
    cout << "p == " << p << ", *p == " << *p << ", i == " << i << ", j == " << j << endl;

    /*
    char c;
    p = &c;
    */

    /*
    p = nullptr;
    cout << "p == " << p << endl;
    cout << "*p == " << *p << endl;
    */

    p = new int{3};
    cout << "p = new int{3};" << endl;
    cout << "p == " << p << ", *p == " << *p << endl;
    delete p;
    p = nullptr;
    delete p;
}
