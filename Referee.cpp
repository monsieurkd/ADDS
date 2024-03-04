#include "Referee.h"
#include "Player.h"
#include "Computer.h"
#include <string>
#include "Move.h"
using namespace std;
// The referee class will match two players and return a reference to the winning player.  In the case of a tie, the referee will return a nullptr.

Referee::Referee(){}; // constructor
Player *Referee::refGame(Player *player1, Player *player2)
{
    Move *a = player1->makeMove();
    Move *b = player2->makeMove();
    // player2 wins
    if ((a->getName() == "Rock" && b->getName() == "Paper") || (a->getName() =="Paper" && b->getName() == "Scissors") || (a->getName()== "Scissors" && b->getName() == "Rock"))
    {
        return player2;
    }
    // player1 win
    else if ((b->getName() == "Rock" && a->getName() == "Paper") || (b->getName() =="Paper" && a->getName() == "Scissors") || (b->getName()== "Scissors" && a->getName() == "Rock"))
    {
        return player1;
    }

    else
    {
        return nullptr;
    }
};