
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v{1, 2};
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    
    v.push_back(3);
    cout << "push_back(4)" << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(4);
    v.push_back(5);
    cout << "push_back(4)" << endl;
    cout << "push_back(4)" << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}
