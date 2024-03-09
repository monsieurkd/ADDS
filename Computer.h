#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
#include "Player.h"
#include "Move.h"
using namespace std;

class Computer : public Player{
    
    public:
        Computer(string name);
        Computer(); 
        string getMove();
        Move * makeMove() override;
        string getName() override;
        

}
;
#endif