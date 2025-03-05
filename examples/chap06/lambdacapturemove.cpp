
#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::unique_ptr<int> pi(new int(1));
    auto f = [x = std::move(pi)]() { return *x; };
    cout << f() << endl;
    auto g = []() { return 0; };
    auto h = [x = g()] { return x; };
    cout << h() << endl;
}
