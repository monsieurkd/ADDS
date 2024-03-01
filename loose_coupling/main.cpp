#include "DieselEngine.h"
#include "PetrolEngine.h"
#include <iostream>
#include "Car.h"

int main()
{
    Dieselengine *d = new Dieselengine();
    Petrolengine *p = new Petrolengine();
    Car *c1 = new Car(d);
    Car *c2 = new Car(p);
    c1->start();
    c2->start();


    return 0;

}
