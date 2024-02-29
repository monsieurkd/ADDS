#include "Human.h"
#include <iostream>
using namespace std;


        Human::Human(string name): name(name){
                        cout << "Enter move: " ;
        cin >> move;
        };
        Human::Human() : name("Human") {
                        cout << "Enter move: " ;
        cin >> move;
        }; 

        char Human::makeMove(){
        

        return move;

        };
        string Human::getName(){
                return this->name;
        };