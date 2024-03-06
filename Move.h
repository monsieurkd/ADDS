#ifndef MOVE_H
#define MOVE_H
#include <string>
class Move
{
protected:
    std::string move;

public:
    Move();
    Move(std::string m);
    std::string getName();
};

class Monkey : public Move
{
public:
    Monkey() : Move("Monkey")
    {
    }
};

class Robot : public Move
{
public:
    Robot() : Move("Robot")
    {
    }
};
class Ninja : public Move
{
public:
    Ninja() : Move("Ninja")
    {
    }
};
class Pirate : public Move
{
public:
    Pirate() : Move("Pirate")
    {
    }
};
class Zombie : public Move
{
public:
    Zombie() : Move("Zombie")
    {
    }
};
class Rock : public Move
{
public:
    Rock() : Move("Rock")
    {
    }
};

class Assign
{
    Move *move;

public:
    Assign(){};
    Assign(std::string name) :
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