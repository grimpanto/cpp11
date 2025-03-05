#include <iostream>
#include <memory>

using namespace std;

void use_ptr(unique_ptr<int>& upi) {
    cout << *upi << endl;
}


int main() {
    unique_ptr<int> upi{new int{1}};
    use_ptr(upi);
}
