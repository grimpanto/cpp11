#include <iostream>

using namespace std;

int main() {

    int i{1};
    int j{2};
    int k{3};

    cout << i + j * k << endl;
    
    cout << i + ++j * k << endl;
    cout << "j = " << j << endl;

    cout << i + j++ * k << endl;
    cout << "j = " << j << endl;

    //    cout << i + ++j++ * k << endl;
    cout << i + (++j)++ * k << endl;
    cout << "j = " << j << endl;
}
