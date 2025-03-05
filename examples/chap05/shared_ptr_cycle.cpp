
#include <iostream>
#include <memory>

using namespace std;

struct Engine;

struct Ship {
    shared_ptr<Engine> engine;
    ~Ship() {
        cout << "Ship destructed" << endl;
    }
};

struct Engine {
    shared_ptr<Ship> ship;
    ~Engine() {
        cout << "Engine destructed" << endl;
    }
};


int main() {
    {
        shared_ptr<Ship> ship{new Ship};
        shared_ptr<Engine> engine{new Engine};
        cout << ship.use_count() << ", " << engine.use_count() << endl;
        ship->engine = engine;
        engine->ship = ship;
        cout << ship.use_count() << ", " << engine.use_count() << endl;
    }
    Ship ship2;
}

