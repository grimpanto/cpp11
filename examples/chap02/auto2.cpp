#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto words = vector<string>{"prolog", "java", "lisp", "python", "c++"};
    
    sort(words.begin(), words.end());

    for (string elem : words) {
        cout << elem << endl;
    }
}
