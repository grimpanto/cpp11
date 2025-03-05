
#include <iostream>

using namespace std;

constexpr unsigned int digitsum(unsigned int number) {
    return (number > 9) ? (number % 10) + digitsum(number / 10) : number;
}

int main() {
    constexpr unsigned int number{digitsum(12345)};
    cout << number << endl;
}
