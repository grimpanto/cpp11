
#include <iostream>
#include <memory>

using namespace std;

int main() {
    shared_ptr<int> spi{new int{1}};

    cout << spi.use_count() << endl;
    {
        shared_ptr<int> spi2{spi};
        cout << spi2.use_count() << endl;
    }
    cout << spi.use_count() << endl;
}

