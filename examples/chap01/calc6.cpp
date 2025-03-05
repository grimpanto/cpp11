
#include <iostream>

using namespace std;

int main() {
    double num1;
    double num2;
    char op;
    double res{};

    cout << "Die erste Zahl: ";
    cin >> num1;
    cout << "Operator [+,-,*,/]: ";
    cin >> op;
    cout << "Die zweite Zahl: ";
    cin >> num2;

    // breaks entfernt!
    switch (op) {
      case '+':
        res = num1 + num2;
      case '-':
        res = num1 - num2;
      case '*':
        res = num1 * num2;
      case '/':
        if (num2 == 0) {
            cerr << "Der Divisor darf nicht 0 sein!" << endl;
            return 1;
        }
        res = num1 / num2;
    }
    
    cout << "Das Ergebnis ist: " << res << endl;
}
