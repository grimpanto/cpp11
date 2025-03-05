#include <iostream>

using namespace std;

void swap(string& a, string& b) {
    string tmp{a};
    a = b;
    b = tmp;
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
