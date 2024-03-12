#include <iostream>
#include <string>
using namespace std;
int reverseDigit(int num)
{
    static int reversedNum = 0;

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



string reverseString(string s){
    if  (s.length() <= 1){
        return s;
    }
        return s.back() + reverseString(s.substr(0, s.length()-1));
    

}

int main(){
    cout<< reverseDigit(123456789) <<endl;
    cout<<reverseString("abcdefgh");
    // string s = "abcdef";
    // cout << s[-1]<<endl;
    // cout<<s.substr(0, s.length()-2);
}