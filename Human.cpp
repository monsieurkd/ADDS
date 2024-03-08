#include "Human.h"
#include "Player.h"
#include "Move.h"
#include <iostream>
using namespace std;
#include <string>

Human::Human(string name) : Player(name)
{
        // cout << "Enter move: "; 
        string move;
        cin >> move;
};
Human::Human() : Player("Human")
{
        // cout << "Enter move: ";
        
};

Move * Human::makeMove()
{
        string move;
        cin >> move;
        Move * m = new Assign(move);

        return m;
};
string Human::getName()
{
        return this->name;
};