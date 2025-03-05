#include <iostream>

using namespace std;

struct Person {
    Person(string name="", double weight=0) { this->name = name; this->weight = weight; }
    string name;
    double weight{};
};

int main() {
    Person p{"Max", 79.5};
    Person q;
    cout << "Name: " << p.name << ", Gewicht: " << p.weight << endl;
    cout << "Name: " << q.name << ", Gewicht: " << q.weight << endl;
}
