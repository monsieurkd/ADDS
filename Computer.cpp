#include "Computer.h"
#include "Move.h"

Computer::Computer(string name) : Player(name){};
Computer::Computer() : Player("Computer"){};

Move *Computer::makeMove()
{
        this->move = new Assign("Robot");
        return this->move;
};
string Computer::getName()
{
        return this->name;
};