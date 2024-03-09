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
{protected:
        vector<string> winHand = {"Ninja",
                            "Zombie"};
public:

    Robot() : Move("Robot")
    {
    }
};
class Ninja : public Move
{   protected:
     vector<string> winHand= {"Pirate",
                            "Zombie"};
public:

    Ninja() : Move("Ninja")
    {
    }
};
class Pirate : public Move
{protected:
        vector<string> winHand= {"Robot",
                             "Monkey"};
public:

    Pirate() : Move("Pirate")
    {
    }
};

class Zombie : public Move
{protected:
        vector<string> winHand = {"Pirate",
                             "Monkey"};
public:

    Zombie() : Move("Zombie")
    {
    }
};
class Rock : public Move
{protected:
    vector<string> winHand = {"Scissors"};

public:

    Rock() : Move("Rock")
    {
    }
};
class Paper : public Move
{protected:
    vector<string> winHand = {"Rock"};

public:

    Paper() : Move("Paper")
    {
    }
};class Scissors : public Move
{protected:
    vector<string> winHand = {"Paper"};

public:

    Scissors() : Move("Scissors")
    {
    }
};
class Assign: public Move
{protected:
    Move *move;

public:
    Assign(){};
    Assign(std::string name) 
    {
        if (name == "Robot")
        {
            move = new Robot();
        }
        else if (name == "Zombie")
        {
            move = new Zombie();
        }
        else if (name == "Ninja")
        {
            move = new Ninja();
        }
        else if (name == "Pirate")
        {
            move = new Pirate();
        }else if (name == "Monkey"){
            move = new  Monkey();
        };
    };

};
#endif