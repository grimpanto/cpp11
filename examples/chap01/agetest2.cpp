#include <iostream>

using namespace std;

int main() {
    int age;

    cout << "Wie alt sind Sie? ";
    cin >> age;
    
    if (age < 18) {
        std::cout << "Sie sind noch minderjährig!" << endl;
    }

    if (age >= 18) {
        std::cout << "Sie sind volljährig!" << endl;
    }
}
