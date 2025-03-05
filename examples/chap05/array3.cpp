
#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 10> arr;
    cout << "size: " << arr.size() << endl;
   
    for (auto i : arr) {
        cout << i << " ";
    }

    array<int, 10> arr2{1, 2, 3};
    cout << "size: " << arr2.size() << endl;
   
    for (auto i : arr2) {
        cout << i << " ";
    }
}
