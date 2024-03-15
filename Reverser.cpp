#include <iostream>
#include "Reverser.h"
#include <string>
using namespace std;

int Reverser::reverseDigit(int num)
{
    static int reversedNum = 0;
    if(num <0){
        return -1;
    }
    // Base case: when the original number becomes 0, return the reversed number
    if (num == 0)
    {
        return 0;
    }

    // Extract the last digit of the number
    int lastDigit = num % 10;
    // Append the last digit to the reversed number
    reversedNum = (reversedNum * 10) + lastDigit;

    // Recursively call the function with the remaining digits of the original number
    reverseDigit(num / 10);

    // When recursion unfolds, the reversed number will be calculated
    return reversedNum;
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

