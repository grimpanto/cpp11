#include <iostream>

using namespace std;

struct Person {
    string name;
    double weight;
};

int main() {
    Person p;
    p.name = "Max";
    p.weight = 79.5;
    Person q;
    cout << "Name: " << p.name << ", Gewicht: " << p.weight << endl;
    cout << "Name: " << q.name << ", Gewicht: " << q.weight << endl;
}
