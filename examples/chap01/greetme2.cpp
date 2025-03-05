#include <iostream>

using namespace std;

int main() {
    string first_name;
    string last_name;
    cout << "Ihr Name bitte: ";
    cin >> first_name;
    cout << "Ihr Nachnamename bitte: ";
    cin >> last_name;
    cout << "Nett Sie zu sehen, " << first_name
         << " " << last_name << "!" << std::endl;
}
