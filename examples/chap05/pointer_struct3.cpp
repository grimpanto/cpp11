
#include <iostream>
#include <memory>

using namespace std;

struct Person {
    string first_name;
    string last_name;
    int year_of_birth;
};

int main() {
    Person* p{new Person{"Max", "Mustermann", 1990}};

    cout << p->first_name << endl;
}

