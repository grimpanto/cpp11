#include <iostream>

using namespace std;

int main() {

    int i{1};
    int j{2};
    int k{3};

    cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
    cout << "i - j - k = " << i - j - k << endl;
    cout << "(i - j) - k = " << (i - j) - k << endl;
    cout << "i - (j - k) = " << i - (j - k) << endl;

    cout << endl;
    
    i = j = k;
    cout << "i = j = k;" << endl;
    cout << "i = " << i << ", j = " << j << ", k = " << k << endl << endl;

    i = 1;
    j = 2;
    k = 3;
    i = (j = k);
    cout << "i = (j = k);" << endl;
    cout << "i = " << i << ", j = " << j << ", k = " << k << endl << endl;

    i = 1;
    j = 2;
    k = 3;
    (i = j) = k;
    cout << "(i = j) = k;" << endl;
    cout << "i = " << i << ", j = " << j << ", k = " << k << endl << endl;

}
