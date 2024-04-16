#include "Sort.h"
#ifndef QUICKSORT_H
#define QUICKSORT_H
class QuickSort : public Sort{
public:
    std::vector<int> sort(std::vector<int> list) override;
};

#endif 