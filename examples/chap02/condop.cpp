#include <iostream>

using namespace std;

int main() {
    int age{};

    cout << "Alter? ";
    cin >> age;
    cout << ((age >= 18) ? "Erwachsen" : "Nicht erwachsen");
}
