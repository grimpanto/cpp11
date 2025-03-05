
#include <iostream>

using namespace std;

constexpr unsigned int digitsum(unsigned int number) {
    return (number > 9) ? (number % 10) + digitsum(number / 10) : number;
}

int main() {
    unsigned int number{};
    cin >> number;
    cout << digitsum(number) << endl;
}
