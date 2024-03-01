#ifndef DIESELENGINE_H
#define DIESELENGINE_H
#include "Iengine.h"

class Dieselengine :public IEngine{
    public:
    void start() override;
};

#endif