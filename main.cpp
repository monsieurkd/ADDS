// The main program will create the referee and players, and then ask the referee to adjudicate a game.   The main function may create any number of players/referees and call play as many times as it wants.

// main will then print the name of the winner.
#include <iostream>
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include <typeinfo>
#include "Move.h"

int main()
{
    Human *human1 = new Human("John"); // Create a human player with the name
    Human *human2 = new Human();


    // Create referee
    Referee referee;

    // Get winner from referee
    Player *winner = referee.refGame(human1, human2);
    cout << human1->getMove();
   


    // Print the name of the winner
    if (winner == nullptr)
    {

        std::cout << "It's a Tie\n";
    }
    else
    {
        std::cout << winner->getName() << " Wins";
    }

    // Free memory
  
    return 0;
}