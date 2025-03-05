#include <iostream>

using namespace std;

void incr(int& counter) {
    ++counter;
}

int main() {
    int counter{};

    incr(counter);
    
    cout << counter << endl;
}
