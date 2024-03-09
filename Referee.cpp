#include "Referee.h"
#include "Player.h"
#include "Computer.h"
#include <string>
#include <vector>
#include <algorithm>
#include "Move.h"
using namespace std;
// The referee class will match two players and return a reference to the winning player.  In the case of a tie, the referee will return a nullptr.

Referee::Referee(){}; // constructor
Player *Referee::refGame(Player *player1, Player *player2)
{
    Move *a = player1->makeMove();
    Move *b = player2->makeMove();
    string  result = a->getName();
    string target = a->getName();
    
    vector<string> winHandA = a->getVector();
    string p1 = player1->getName();

    string p2 = player2->getName();

   



    if (p1 == p2)
    {
        return nullptr;
    }

    for (int i = 0; i <winHandA.size(); i++){
        if(winHandA[i]==target){
            return player1;
    }
    

        return player2;
    
    // player2 wins
};