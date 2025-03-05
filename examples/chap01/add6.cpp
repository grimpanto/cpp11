
#include <iostream>

using namespace std;

int main() {
    int num1;
    int num2;

    cout << "Die erste Zahl: ";
    cin >> num1;
    cout << "Die zweite Zahl: ";
    cin >> num2;
    
    cout << "Das Ergebnis ist: " << num1 + num2 << endl;

    // Behandlung des Rests hinzugefügt
    string rest;
    cin >> rest;
    cout << "Der verbleibende Rest: " << rest << endl;
}
