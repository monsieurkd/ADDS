#include "Computer.h"

        Computer::Computer(string name): name(name){};
        Computer::Computer() : Player("Computer") {}; 

        char Computer::makeMove(){
                return 'R';
        };
        string Computer::getName(){
                return  this->name;
        };