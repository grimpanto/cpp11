#include <iostream>

using namespace std;

class Person {
  public:
    Person(string name="", double weight=0) : name{name}, weight{weight} { }
    string get_name() { return name; }
    double get_weight() { return weight; }
  private:
    string name;
    double weight;
};

int main() {
    Person p{"Max", 79.5};
    Person q;
    cout << "Name: " << p.get_name() << ", Gewicht: " << p.get_weight() << endl;
    cout << "Name: " << q.get_name() << ", Gewicht: " << q.get_weight() << endl;

    Person r{p};
    cout << "Name: " << r.get_name() << ", Gewicht: " << r.get_weight() << endl;

    r = q;
    cout << "Name: " << r.get_name() << ", Gewicht: " << r.get_weight() << endl;
}
