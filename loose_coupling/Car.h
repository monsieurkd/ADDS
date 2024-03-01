#ifndef CAR_H
#define CAR_H

#include "IEngine.h"
class Car
{
private:
    IEngine *engine;

public:
    Car(IEngine* e);
    ~Car();
    void start();
};
#endif