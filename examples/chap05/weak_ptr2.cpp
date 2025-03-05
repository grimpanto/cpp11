
#include <memory>
#include <iostream>

using namespace std;

int main() {
    weak_ptr<int> wpi;
    {
        auto spi = make_shared<int>(1);
        wpi = spi;
    }
    cout << *(wpi.lock()) << endl;
}
