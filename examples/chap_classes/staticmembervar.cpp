
#include <iostream>

using namespace std;

class Car {
  public:
    Car() : sernr_{maxsernr} { maxsernr++; }
    int sernr() { return sernr_; }
  private:
    static int maxsernr;
    int sernr_;
};

int Car::maxsernr{1};

int main() {
    Car c1;
    Car c2;
    Car c3;
    cout << "c1: " << c1.sernr() << endl;
    cout << "c2: " << c2.sernr() << endl;
    cout << "c3: " << c3.sernr() << endl;
}
