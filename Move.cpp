#include "Move.h"
#include <string>
#include <vector>
using namespace std;
Move::Move(){};
Move::Move(string m):move(m){};

string Move::getName(){
    return this->move;
}
 vector<string> Move::getVector(){
    return winHand;
}