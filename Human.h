#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Human : public Player{
    char move;
    string name;
    public:
        Human(string name);
        Human(); 

        char makeMove() override;
        string getName() override;
        

}
;


#endif