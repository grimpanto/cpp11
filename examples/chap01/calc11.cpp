
#include <iostream>

using namespace std;

int main() {
    double num1;
    double num2;
    char op;
    double res{};
    char proceed;
    
    do {
        cout << "Die erste Zahl: ";
        if (!(cin >> num1)) {
            cerr << "Keine gültige Zahl. Abbruch" << endl;
            return 1;
        }
        cout << "Operator [+,-,*,/]: ";
        cin >> op;
        cout << "Die zweite Zahl: ";
        if (!(cin >> num2)) {
            cerr << "Keine gültige Zahl. Abbruch" << endl;
            return 1;
        }

        switch (op) {
          case '+':
            res = num1 + num2;
            break;
          case '-':
            res = num1 - num2;
            break;
          case '*':
            res = num1 * num2;
            break;
          case '/':
            if (num2 == 0) {
                cerr << "Der Divisor darf nicht 0 sein!" << endl;
                return 1;
            }
            res = num1 / num2;
            break;
          default:
            cerr << "Kein gültiger Operator. Abbruch" << endl;
            return 1;
        }
        cout << "Das Ergebnis ist: " << res << endl;
        cout << "Weiter? [y/n] ";
        cin >> proceed;
        cout << endl;
    } while (proceed == 'y');
}
