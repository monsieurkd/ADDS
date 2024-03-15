#include "Reverser.h"
#include "Truckloads.h"
#include <iostream>
using namespace std;




int main(){
    Reverser r1,r2;
    cout << r1.reverseDigit(987654321);
    cout << r2.reverseString("Hello World") << endl;
    Truckloads a;
    cout << a.numTrucks(1024,5);
    

}
