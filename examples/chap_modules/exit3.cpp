
#include <iostream>
#include <cstdlib>

using namespace std;

struct Variable {
    string name;
    ~Variable() {
        cout << name << " var destructed" << endl;
    }
};

void exit_handler() {
    cout << "exit handler called..." << endl;
}

int main() {
    Variable local_var{"local"};
    static Variable static_var{"static"};

    int result = atexit(exit_handler);
 
    if (result != 0) {
        cout << "exit_handler registration failed" << endl;
        return EXIT_FAILURE;
    }
    
    exit(EXIT_SUCCESS);
}
