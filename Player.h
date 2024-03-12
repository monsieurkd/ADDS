#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Move.h"
using namespace std;

class Player
{
    protected:
    string name;
    Move * move;

public:
    Player(string name);
    Player();

    virtual Move* makeMove()=0;
    virtual string getName()=0;
    virtual ~Player();
};

#endif