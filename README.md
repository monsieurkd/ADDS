g++ -o main.out -std=c++11 -O2 -Wall *.cpp

SOLID design
To extend your referee

 modify your refGame() so that it complies with SOLID principles.  refGame()  work without modification for any types of moves, continue to support the Rock, Paper and Scissor options.  Consider how you can use Polymorphism to achieve this.


Player (abstract class)

Move * makeMove( );  // return type is changed, the return type of this is a hint to the polymorphism
string getName( ); // returns the name of the Player as a string

IMPORTANT CHANGE: since we now have different moves that start with the same letter, when a move is typed on the keyboard, the user will now enter the full name of the move.   For example:

Enter Move: Ninja

The list of possible values the user might enter are:

Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie
Referee

Referee( ); // constructor

Player * refGame(Player * player1, Player * player2)
// returns the reference to the winning player

Move

string getName(); // returns the name of a Move instance, for example "Ninja".  This function exists so I can do some tests.  You are not required to call it in your code but you may find it useful.

player có một đống instance và ref sét instance của player, giờ player lại dựa theo các instance khác nhau của move