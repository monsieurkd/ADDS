// The main program will create the referee and players, and then ask the referee to adjudicate a game.   The main function may create any number of players/referees and call play as many times as it wants.

// main will then print the name of the winner.
#include <iostream>
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
using namespace std;

int main()
{
    Human *human = new Human("Mei");
    Player *computer = new Computer();

    // Create referee
    Referee referee;

    // Get winner from referee
    Player *winner = referee.refGame(human, computer);
    
    // Print the name of the winner
    if (winner == nullptr){
        
        std::cout << "It's a Tie\n";
    }
    else
    {
        std::cout << winner->getName()<< " Wins";
    }

    // Free memory
    delete human;
    delete computer;

    return 0;
}