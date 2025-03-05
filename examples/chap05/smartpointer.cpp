
#include <iostream>
#include <memory>

using namespace std;

int main() {
    {
        unique_ptr<int> pi{new int{1}};
    }
}
