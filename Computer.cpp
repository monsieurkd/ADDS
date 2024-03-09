#include "Computer.h"
#include "Move.h"

Computer::Computer(string name) : Player(name){};
Computer::Computer() : Player("Computer"){};

Move *Computer::makeMove()
{
        this->move = new Assign("Rock");
        return this->move;
};

string Computer::getMove(){
        Move * a = this->move;
        return a->getName();
}
string Computer::getName()
{
        return this->name;
};