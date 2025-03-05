
#include <iostream>

using namespace std;

int main() {
    double num1;  // <-- int zu double
    double num2;  // <-- int zu double
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
        if (num2 == 0) {
            cerr << "Der Divisor darf nicht 0 sein!" << endl;
            return 1;
        }
        cout << "Das Ergebnis ist: " << num1 / num2 << endl;
    }
}
