#ifndef MOVE_H
#define MOVE_H
#include <string>
class Move
{
    protected:
    std::string move;

public:
Move();
Move(std::string m);
std::string getName();
};

class Rock : public Move{
    public:
    Rock() : Move("Rock") {
        
    }
};

#endif