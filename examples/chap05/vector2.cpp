
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v{1, 2};
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    
    v.push_back(3);

    cout << "push_back(3)" << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}
