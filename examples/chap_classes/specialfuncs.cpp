
#include <iostream>

using namespace std;

string ident(string arg) {
    return arg;
}

int main() {
    string s1{"xxx"}; // constructor
    s1 = ident(s1);  // copy s1 into ident; move result into s1
    string s2{"yyy"};
    s1 = s2;  // copy s2 into s1 (assignment)
}
