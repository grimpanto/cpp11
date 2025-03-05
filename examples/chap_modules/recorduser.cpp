
#include <iostream>

using namespace std;

using T = char;
#include "record.h"

int main() {
    Record rec;
    rec.id = 'a';
    cout << get_id(&rec) << endl;
}
