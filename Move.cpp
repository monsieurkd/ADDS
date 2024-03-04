#include "Move.h"
#include <string>
using namespace std;
Move::Move(){};
Move::Move(string m):move(m){};

string Move::getName(){
    return this->move;
}
