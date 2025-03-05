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

    int v[]{9,9,9,9,9};
    i = 1;
    v[i] = i++;
    cout << "v[1] = " << v[1] << endl;
    cout << "v[2] = " << v[2] << endl;
}
