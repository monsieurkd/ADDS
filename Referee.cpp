#include "Referee.h"
#include "Player.h"
#include "Computer.h"
// The referee class will match two players and return a reference to the winning player.  In the case of a tie, the referee will return a nullptr.

Referee::Referee(){}; // constructor
Player *Referee::refGame(Player *player1, Player *player2)
{
    char a = player1->makeMove();
    char b = player2->makeMove();
    // player2 wins
    if ((a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R'))
    {
        return player2;
    }
    // player1 win
    else if ((b == 'R' && a == 'P') || (b == 'P' && a == 'S') || (b == 'S' && a == 'R'))
    {
        return player1;
    }

    else
    {
        return nullptr;
    }
};