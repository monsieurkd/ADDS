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
    string p1 = a->getName();
    Move *b = player2->makeMove();
    string p2 = b->getName();
    vector<string> Robot = {"Ninja",
                            "Zombie"};
    vector<string> Monkey = {"Ninja",
                             "Robot"};
    vector<string> Pirate = {"Robot",
                             "Monkey"};
    vector<string> Ninja = {"Pirate",
                            "Zombie"};
    vector<string> Zombie = {"Pirate",
                            "Monkey"};
    vector<string> Rock = {"Scissors"};
    vector<string> Paper= {"Rock"
                            };
    vector<string> Scissors = {"Paper"
                            };

    if (p1 == p2){
        return nullptr;
    }
    else if ((p1 == "Ninja") && (find(Ninja.begin(), Ninja.end(), p2) != Ninja.end())) {

        return player1; 
    } 
        else if ((p1 == "Robot") && (find(Robot.begin(), Robot.end(), p2) != Robot.end())) {

        return player1; 
    } 
        else if ((p1 == "Monkey") && (find(Monkey.begin(), Monkey.end(), p2) != Monkey.end())) {

        return player1; 
    } 
        else if ((p1 == "Pirate") && (find(Pirate.begin(), Pirate.end(), p2) != Pirate.end())) {

        return player1; 
    } 
        else if ((p1 == "Zombie") && (find(Zombie.begin(), Zombie.end(), p2) != Zombie.end())) {

        return player1; 
    } 
    else if ((p1 == "Rock") && (find(Rock.begin(), Rock.end(), p2) != Rock.end())) {

        return player1; 
    } 
    else if ((p1 == "Paper") && (find(Paper.begin(), Paper.end(), p2) != Paper.end())) {

        return player1; 
    } else if ((p1 == "Scissors") && (find(Scissors.begin(), Scissors.end(), p2) != Scissors.end())) {

        return player1; 
    } else{
        return player2;
    }
    // player2 wins
   

};