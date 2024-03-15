#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser{
    public:
    int reverseDigit(int n, int accumulative = 0);
    std::string reverseString(std::string s);
}
;
#endif //REVERSER_H