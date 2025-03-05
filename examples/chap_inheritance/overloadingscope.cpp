
#include <iostream>

using namespace std;

class DoubleAccumulator {
  protected:
    double counter{0};
  public:
    virtual void incr(double d) {
        counter += d;
        cout << "incr by double: " << d << endl;
    }
    virtual void incr(const char* t) {
        cout << "Base: " << t << endl;
    }
};

class IntAccumulator : public DoubleAccumulator {
  public:
    void incr(int i) {
        counter += i;
        cout << "incr by int: " << i << endl;
    }
    virtual void incr(const char* t) {
        cout << "Derived: " << t << endl;
    }
};

int main() {
    IntAccumulator ia;
    ia.incr(0.5);
    DoubleAccumulator& da{ia};
    da.incr(1.5);
    da.incr(2);
    DoubleAccumulator* dap{&ia};
    dap->incr(2.5);
    dap->incr(3);
    dap->incr("abc");
}
