
#include <iostream>

using namespace std;

int main() {
    int num1;
    int num2;
    int res{0};  // <-- 

    cout << "Die erste Zahl: ";
    cin >> num1;
    cout << "Die zweite Zahl: ";
    cin >> num2;

    res = num1 + num2;
    
    cout << "Das Ergebnis ist: " << res << endl;
}
