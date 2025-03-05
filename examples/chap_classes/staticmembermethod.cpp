
#include <iostream>

using namespace std;

class Car {
  public:
    static Car* make_car(string type);
};

class Andi : public Car {
};

class Zitrone : public Car {
};


Car* Car::make_car(string type) {
    if (type == "Andi")
        return new Andi();
    else if (type == "Zitrone")
        return new Zitrone();
    else
        return nullptr;
}

int main() {
    string type;
    cout << "Autotype: ";
    cin >> type;
    Car* car{Car::make_car(type)};
}
