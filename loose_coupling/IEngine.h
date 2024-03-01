//class with virtual function start and virtual destuctor

#ifndef IENGINE_H
#define IENGINE_H

class IEngine {
    public:
    virtual  void start() = 0;
    virtual ~IEngine(){};

};
#endif
