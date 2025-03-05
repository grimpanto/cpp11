
#include <iostream>
#include <memory>

using namespace std;

int main() {
    /*
      for (int i{0}; i < 1000; ++i) {
        int j;
        cout << j << ' ';
        j = i;
        cout << j << ' ';
    }
    */
    int x{3};
    int& y{x};
    int& z{y};
    int x1{1};

}
