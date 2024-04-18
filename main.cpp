#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

#include <vector>
using namespace std;

int main(){

    BubbleSort bs;
    vector<int> a = {1,2,3,8,9,1,2};
    vector<int> c = {1,2,3,8,9,1,2};


    QuickSort qs;
    vector<int> d = qs.sort(a);
    RecursiveBinarySearch rbs;
    bool search = rbs.search(d, 1);
    cout << (search ? "true" : "false") << " ";
    for (std::vector<int>::size_type i = 0; i < d.size(); i ++){
        cout << d[i] << " ";
    }
    return 0;
}
