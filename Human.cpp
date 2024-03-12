#include "Human.h"
#include "Player.h"
#include "Move.h"
#include <iostream>
using namespace std;
#include <string>

Human::Human(string name) : Player(name)
{
        // cout << "Enter move: "; 
       
        
};
Human::Human() : Player("Human")
{
        // cout << "Enter move: ";
        
};

Move * Human::makeMove()
{
        string move;
        cin >> move;
        Assign assigner;
        this->move = assigner.AssignMove(move);

        return this->move;
};

string Human::getMove(){
        Move * a = this->move;
        return a->getName();
}

string Human::getName()
{
        return this->name;
};