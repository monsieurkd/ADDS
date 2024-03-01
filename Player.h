#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player
{
    protected:
    string name;

public:
    Player(string name);
    Player();

    virtual char makeMove()=0;
    virtual string getName()=0;
    virtual ~Player();
};

#endif