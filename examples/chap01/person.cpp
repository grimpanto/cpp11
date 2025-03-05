
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string first_name;
    string last_name;
    int year_of_birth;
};

int main() {
    Person p1{"Max", "Mustermann", 1990};
    Person p2{"Otto", "Normalverbraucher", 1950};
    Person p3{"Susi", "Musterfrau", 1991};
    
    vector<Person> persons{p1, p2, p3};
    sort(persons.begin(), persons.end(), [](Person p1, Person p2) { return p1.year_of_birth < p2.year_of_birth; });

    for (auto p : persons) {
        cout << p.first_name << " " << p.last_name << " " << p.year_of_birth << endl;
    }
}
