
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    vector<function<string()>> v;
    {
        string name{"Bob"};
        v.push_back([&name]() { return name; });
    }
    cout << v[0]() << endl;
}
