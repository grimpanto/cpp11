
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Polyline {
  public:
    Polyline(initializer_list<pair<double, double>> points) : points{points} {}
    void add(double x, double y) { points.emplace_back(x, y); distance = -1; }
    double length();
  private:
    vector<pair<double, double>> points;
    mutable double distance{-1};
};

int main() {
    Polyline poly1{{}};
    cout << poly1.length() << endl;
    poly1.add(0, 0);
    cout << poly1.length() << endl;
    poly1.add(1, 1);
    cout << poly1.length() << endl;
    poly1.add(2, 0);
    cout << poly1.length() << endl;

    const Polyline poly2{{0, 0}, {1, 1}, {2, 0}};
    // poly2.add(3, 3);
    cout << poly2.length() << endl;
}
