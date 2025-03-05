#include <iostream>

using namespace std;

class Person {
  public:
    Person(string name="", double weight=0) : name_{name}, weight_{weight} { }
    string name(string name="") { if (name != "") name_ = name; return name_; }
    double weight(double weight=0) { if (weight > 0) weight_ = weight; return weight_;}
  private:
    string name_;
    double weight_;
};

int main() {
    Person p{"Max", 79.5};
    Person q;
    cout << "Name: " << p.name() << ", Gewicht: " << p.weight() << endl;
    q.name("Mini");
    q.weight(60);
    cout << "Name: " << q.name() << ", Gewicht: " << q.weight() << endl;

    Person r{p};
    cout << "Name: " << r.name() << ", Gewicht: " << r.weight() << endl;

    r = q;
    cout << "Name: " << r.name() << ", Gewicht: " << r.weight() << endl;
}
