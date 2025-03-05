
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Polyline {
  public:
    Polyline(initializer_list<pair<double, double>> points);
    void add(double x, double y);
    double length() const;
};
