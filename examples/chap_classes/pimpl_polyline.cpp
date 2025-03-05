#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class PolylineImpl {
  public:
    PolylineImpl(initializer_list<pair<double, double>> points) : points{points} {}
    void add(double x, double y) { points.emplace_back(x, y); distance = -1; }
    double length() const {
        if (distance >= 0)
            return distance;
        else {
            const pair<double, double>* p_prev{};
            for (auto& p : points) {
                if (!p_prev) {
                    p_prev = &p;
                    distance = 0;
                    continue;
                }
                distance += sqrt(pow(p.first - p_prev->first, 2) + pow(p.second - p_prev->second, 2));
                p_prev = &p;
            }
            return distance;
        }
    }
  private:
    vector<pair<double, double>> points;
    mutable double distance{-1};
};



class Polyline {
  public:
    Polyline(initializer_list<pair<double, double>> points) : impl{new PolylineImpl{points}} {}
    void add(double x, double y) { impl->add(x, y); }
    double length() const { return impl->length(); }
    ~Polyline() { delete impl; }
  private:
    PolylineImpl* impl;
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
