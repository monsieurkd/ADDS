#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <vector>
using namespace std;
class Move
{
protected:
    std::string move;
    std::vector<string> winHand;

public:
    Move();
    Move(std::string m);
    std::string getName();
    vector<string> getVector();
};

class Monkey : public Move
{
protected:
    vector<string> winHand = {"Ninja",
                              "Robot"};

public:
    Monkey() : Move("Monkey")
    {
    }
};

class Robot : public Move
{
protected:
    vector<string> winHand = {"Ninja",
                              "Zombie"};

public:
    Robot() : Move("Robot")
    {
    }
};
class Ninja : public Move
{
protected:
    vector<string> winHand = {"Pirate",
                              "Zombie"};

public:
    Ninja() : Move("Ninja")
    {
    }
};
class Pirate : public Move
{
protected:
    vector<string> winHand = {"Robot",
                              "Monkey"};

public:
    Pirate() : Move("Pirate")
    {
    }
};

class Zombie : public Move
{
protected:
    vector<string> winHand = {"Pirate",
                              "Monkey"};

public:
    Zombie() : Move("Zombie")
    {
    }
};
class Rock : public Move
{
protected:
    vector<string> winHand = {"Scissors"};

public:
    Rock() : Move("Rock")
    {
    }
};
class Paper : public Move
{
protected:
    vector<string> winHand = {"Rock"};

public:
    Paper() : Move("Paper")
    {
    }
};
class Scissors : public Move
{
protected:
    vector<string> winHand = {"Paper"};

public:
    Scissors() : Move("Scissors")
    {
    }
};
class Assign {
public:
    Move* AssignMove(std::string name) {
        if (name == "Robot") {
            return new Robot();
        } else if (name == "Zombie") {
            return new Zombie();
        } else if (name == "Ninja") {
            return new Ninja();
        } else if (name == "Pirate") {
            return new Pirate();
        } else if (name == "Monkey") {
            return new Monkey();
        } else if (name == "Rock") {
            return new Rock();
        } else if (name == "Paper") {
            return new Paper();
        } else if (name == "Scissors") {
            return new Scissors();
        } else {
            // Handle the case when the input name doesn't match any condition
            return nullptr;
        }
    }
};
#endif