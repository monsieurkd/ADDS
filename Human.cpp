#include "Human.h"
#include "Player.h"
#include <iostream>
using namespace std;

Human::Human(string name) : Player(name)
{
        // cout << "Enter move: "; 
        cin >> move;
};
Human::Human() : Player("Human")
{
        // cout << "Enter move: ";
};

char Human::makeMove()
{
        cin >> move;

        return move;
};
string Human::getName()
{
        return this->name;
};