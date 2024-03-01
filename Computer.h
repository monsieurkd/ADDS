#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Computer : public Player{
    
    public:
        Computer(string name);
        Computer(); 

        char makeMove() override;
        string getName() override;
        

}
;
#endif