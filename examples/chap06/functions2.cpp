#include <iostream>

using namespace std;

double squared(double);
void print(string msg);
int one();

int main() {
    print("2^2 - 1 = ");
    cout << squared(2) - one() << endl;
}
