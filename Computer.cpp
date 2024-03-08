#include "Computer.h"
#include "Move.h"

Computer::Computer(string name) : Player(name){};
Computer::Computer() : Player("Computer"){};

Move *Computer::makeMove()
{
        Assign *m = new Assign("Rock");
        return m;
};
string Computer::getName()
{
        return this->name;
};