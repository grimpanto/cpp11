#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

//int f() { return 1; }

class A {
  public:
    A(const A&) {
        cout << "copy cons" << endl;
    }
    A(A&&) {
        cout << "move cons" << endl;
    }
    A() = default;  
};


A f(A a) {
    return a;
}


class B {
  public:
    int a;
    int b;
};

int f(int& i) {
    cout << &i << endl;
}

int main(int argc, char* argv[]) {
    /*decltype(1.0f + 1.0f) x;
    cout << typeid(x).name() << endl;
    cout << typeid(1 + 2l).name() << endl;
    */

    //cout << '0' + '1' << endl;

    //    cout << 0b00001111 << endl;
    //cout << 1'000'000 << endl;  // C++14

    unsigned x;
    signed y;
    /*
    int i;
    int* p{&i};
    const int j{1};
    
    i = 3;
    *p = 4;
    //    j = 2; // Compilerfehler: kein lvalue
    */

    /*
    bool b{};
    b++;
    cout << b << endl;
    b++;
    cout << b << endl;
    b+=1;
    cout << b << endl;
    */

    /*
    bool b{true};
    b %= 2;
    cout << b << endl;
    */

    /*
    A a;
    //A b{a};
    A c{f(a)};
    */
    
    /*
    string f{};
    f = "abc";
    */

    //B d{1, 2};

    /*
    // C++14
    auto Identity = [](auto a) { return a; };

    int three = Identity(3);

    char const* hello = Identity("hello");
    */

    /*
    int i{3};
    cout << &i << endl;
    f(i);
    */

    /*
    auto lambda = [] (auto x, auto y)
        { return x<y; };
    */

    /*
    constexpr double pi{atan(1)*4};
    cout << pi << endl;
    */
}
