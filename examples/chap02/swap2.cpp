#include <iostream>

using namespace std;

void swap(string& a, string& b) {
    string tmp{static_cast<string&&>(a)};
    a = static_cast<string&&>(b);
    b = static_cast<string&&>(tmp);
}

int main() {
    string s1{"foo"};
    string s2{"bar"};

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    swap(s1, s2);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
}
