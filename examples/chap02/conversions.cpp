#include <iostream>

using namespace std;
    
int main() {
    long long int ll{};
    char c{};

    cout << "sizeof(ll) = " << sizeof(ll) << endl;
    cout << "sizeof(c) = " << sizeof(c) << endl;
    cout << "sizeof(l + c) = " << sizeof(ll + c) << endl;
}
