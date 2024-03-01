#include "Referee.h"
#include "Player.h"
#include "Computer.h"
//The referee class will match two players and return a reference to the winning player.  In the case of a tie, the referee will return a nullptr.

Referee::Referee(){}; // constructor
Player * Referee::refGame(Player * player1, Player * player2){
char a = player1->makeMove();
char b = player2->makeMove() ;
if((a == 'R' && b=='P') or (a == 'P' && b=='S') or (a == 'S' && b=='R')){  return player2; }
else if((b == 'R' && a=='P') or (b == 'P' && a=='S') or (b == 'S' && a=='R')){  return player1; }


    else{
        return nullptr;
    }
};