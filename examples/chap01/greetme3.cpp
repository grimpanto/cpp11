#include <iostream>

using namespace std;

int main() {
    string name;
    cout << "Ihr Name bitte: ";
    getline(cin, name);
    cout << "Nett Sie zu sehen, " << name << "!" << std::endl;
}
