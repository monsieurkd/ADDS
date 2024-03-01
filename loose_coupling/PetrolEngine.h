#ifndef PETROLENGINE_H
#define PETROLENGINE_H
#include "Iengine.h"

class Petrolengine :public IEngine{
    public:
    void start() override;
};

#endif