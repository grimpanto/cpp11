#include <iostream>

using namespace std;

string f() {
    return "f()"; 
}

int main() {
    string res{f()};
    cout << res << endl;
}
