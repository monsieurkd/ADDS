#include "Car.h"
#include <iostream>
Car::Car(IEngine *e) : engine(e){};
Car::~Car(){};
void Car::start()
{
    engine->start();
    std::cout << "car running";
};
