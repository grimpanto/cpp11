
#include <iostream>

using namespace std;

void log(initializer_list<string> messages) {
    for (auto msg : messages) {
        cout << msg << endl;
    }
}

int main() {
    log({"testing", "warning", "error"});
}
