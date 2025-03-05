#include <iostream>
#include <chrono>

using namespace std;

int main() {
    constexpr size_t max{100000};

    auto start = std::chrono::system_clock::now();

    for (int i{0}; i < max; ++i) {
        long long buffer[max];
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << elapsed.count() << "ms" << endl;
}
