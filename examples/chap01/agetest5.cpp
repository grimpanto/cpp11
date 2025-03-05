#include <iostream>

using namespace std;

int main() {
    int age;

    cout << "Wie alt sind Sie? ";
    cin >> age;

    if (age < 14) {
        std::cout << "Du bist noch ein Kind." << endl;
    } else if (age < 18) {
        std::cout << "Sie sind ein Jugendlicher!" << endl;
    } else {
        std::cout << "Sie sind volljährig!" << endl;
    }
}
