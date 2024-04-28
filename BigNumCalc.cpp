#include "BigNumCalc.h"
using namespace std;
#include <iostream>

BigNumCalc::BigNumCalc(){}
std::list<int> BigNumCalc::buildBigNum(std::string numString){
    list<int> a; 
    for (char &i: numString){   
        a.push_back(i - '0');
    }
    return a;
}
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    list<int>::reverse_iterator i = num1.rbegin(); //reverse iterator
    list<int>::reverse_iterator j = num2.rbegin();
    int sum2digits = 0; 
    std::list<int> sum;
    int carry = 0;
    while (i != num1.rend() && j != num2.rend()){
        int sum2digits = *i + *j + carry; 
        if (sum2digits >= 10){
            sum2digits -= 10; 
            carry = 1; 
        } else {
            carry = 0;
        }
        sum.emplace_front(sum2digits);
        ++i; 
        ++j;
    }
    while (i != num1.rend()){
        sum2digits = carry + *i; 
        if (sum2digits >= 10){
            sum2digits -= 10; 
            carry = 1; 
        } else {
            carry = 0;
        }
        sum.emplace_front(sum2digits);
        ++i;
    }
    while (j != num2.rend()){
        sum2digits = carry + *j; 
        if (sum2digits >= 10){
            sum2digits -= 10; 
            carry = 1; 
        } else {
            carry = 0;
        }
        sum.emplace_front(sum2digits);
        ++j;
    }
    if (carry != 0){
        sum.emplace_front(carry);
    }
    return sum; 
} 
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    list<int>::reverse_iterator i = num1.rbegin(); //reverse iterator
    list<int>::reverse_iterator j = num2.rbegin();
    int carry = 0;
    int diff2digits = 0;
    list<int> diff;
    while (j != num2.rend()){
        diff2digits = *i - carry - *j;
        if (diff2digits < 0){
            diff2digits = 10 + *i - *j - carry;
            carry = 1; 
        } else {
            carry = 0;
        } 
        ++j;
        ++i;
        diff.emplace_front(diff2digits);
    }
    while (i != num1.rend()){
        diff2digits = *i - carry;
        if (diff2digits <0){
            diff2digits = 10 + *i - carry;
            carry = 1; 
        } else {
            carry = 0;
        }
        ++i; 
        diff.emplace_front(diff2digits);

    }
    if (diff.empty()) {
        diff.push_back(0); 
    }
    return diff;
} 
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){\
    list<int>::reverse_iterator i = num1.rbegin(); //reverse iterator
    int carry = 0; 
    int mult2digits = 0; 
    list<int> mult; 
    while (i != num1.rend()){
        mult2digits = (*i) * (*num2.begin()) + carry; 

        if (mult2digits >= 10) {
            carry = mult2digits / 10; 
            mult2digits = mult2digits - carry * 10;
        } else {
            carry = 0;
        }
        ++i;
        mult.emplace_front(mult2digits); 
    } 
    if (carry != 0) {
        mult.emplace_front(mult2digits);
    }
    return mult;
}