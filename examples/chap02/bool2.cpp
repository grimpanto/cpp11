#include <iostream>

using namespace std;

int main() {
    bool ready{};
    char answer;

    while (!ready) {
        cout << "[y/n] ";
        cin >> answer;
        ready = (answer == 'y' || answer == 'n');
        ready = (answer == 'y') ? true : false;
    }

    cout << "Antwort: " << answer << endl;
}
