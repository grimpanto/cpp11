
#include <iostream>

using namespace std;

int main() {
    int num1;
    int num2;
    char op;

    cout << "Die erste Zahl: ";
    cin >> num1;
    cout << "Operator [+,-,*,/]: ";
    cin >> op;
    cout << "Die zweite Zahl: ";
    cin >> num2;

    if (op == '+') {
        cout << "Das Ergebnis ist: " << num1 + num2 << endl;
    } else if (op == '-') {
        cout << "Das Ergebnis ist: " << num1 - num2 << endl;
    } else if (op == '*') {
        cout << "Das Ergebnis ist: " << num1 * num2 << endl;
    } else if (op == '/') {
        cout << "Das Ergebnis ist: " << num1 / num2 << endl;
    }
}
