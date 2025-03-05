
#ifndef INLINE_CAR_H
#define INLINE_CAR_H

#include <iostream>

class Car {
  public:
    void drive();
};

inline void Car::drive() { std::cout << "now driving..." << std::endl; }

#endif
