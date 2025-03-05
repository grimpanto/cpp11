
#include <iostream>

using namespace std;

class Adder {
  public:
    Adder& add(int val) { amount += val; return *this; }
    int value() const { return amount; }
  private:
    int amount{};
};

int main() {
    Adder a;
    a.add(1).add(2).add(3);
    cout << a.value() << endl;

    const Adder b;
    //    b.add(1).add(2).add(3);
    cout << b.value() << endl;
}
