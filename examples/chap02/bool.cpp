#include <iostream>

using namespace std;

int main() {
    bool ready{};
    char answer;

    while (!ready) {
        cout << "[y/n] ";
        cin >> answer;
        ready = (answer == 'y' || answer == 'n');
    }

    cout << "Antwort: " << answer << endl;
}
