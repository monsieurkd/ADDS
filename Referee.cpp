#include "Referee.h"
#include "Player.h"
#include "Computer.h"
//The referee class will match two players and return a reference to the winning player.  In the case of a tie, the referee will return a nullptr.

Referee::Referee(){}; // constructor
Player * Referee::refGame(Player * player1, Player * player2){
    if (player1->makeMove() == 'R' and player2->makeMove()  == 'P'){
        return player2;

    }else if( player1->makeMove() == 'R' and player2->makeMove() == 'S'){
        return player1;
    } else{
        return nullptr;
    }
};