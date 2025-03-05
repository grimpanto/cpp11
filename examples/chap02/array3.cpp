#include <iostream>

using namespace std;

int main() {
    char firstname[]{"Maxi"};
    cout << firstname << endl;

    char* lastname{"Mustermann"};
    cout << lastname << endl;

    lastname[0] = 'm';
}
