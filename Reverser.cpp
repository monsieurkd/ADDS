#include <iostream>
#include "Reverser.h"
#include <string>
using namespace std;

int Reverser::reverseDigit(int num, int accumalative)
{
    
    if(num <0){
        return -1;
    }
    // Base case: when the original number becomes 0, return the reversed number
    if (num == 0)
    {
        return accumalative;
    }

    // Extract the last digit of the number
    int lastDigit = num % 10;
    // Append the last digit to the reversed number
    accumalative = (accumalative * 10) + lastDigit;

    // Recursively call the function with the remaining digits of the original number
    return reverseDigit(num / 10, accumalative );

    // When recursion unfolds, the reversed number will be calculated
}



string Reverser::reverseString(string s){
    if (s.length() ==0){
        return "ERROR";
    }
    if  (s.length() == 1){
        return s;
    }
        return s.back() + reverseString(s.substr(0, s.length()-1));
    

}

