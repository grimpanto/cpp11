
#include <iostream>
#include <cstdlib>

using namespace std;

struct Variable {
    string name;
    ~Variable() {
        cout << name << " var destructed" << endl;
    }
};


int main() {
    Variable local_var{"local"};
    static Variable static_var{"static"};

    exit(EXIT_SUCCESS);
}
