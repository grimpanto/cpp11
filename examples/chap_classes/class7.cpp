#include <iostream>

using namespace std;

struct Person {
    Person(string name="", double weight=0) : name{name}, weight{weight} { }
    string name;
    double weight;
};

int main() {
    Person p{"Max", 79.5};
    Person q;
    cout << "Name: " << p.name << ", Gewicht: " << p.weight << endl;
    cout << "Name: " << q.name << ", Gewicht: " << q.weight << endl;

    Person r{p};
    cout << "Name: " << r.name << ", Gewicht: " << r.weight << endl;

    r = q;
    cout << "Name: " << r.name << ", Gewicht: " << r.weight << endl;
}
