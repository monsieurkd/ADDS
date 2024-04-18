#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

#include <vector>
using namespace std;

int main(){

    vector<int> input_list;
    int num;
    while (cin >> num) {
        input_list.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    QuickSort qs;
    vector<int> d = qs.sort(input_list);
    RecursiveBinarySearch rbs;
    bool search = rbs.search(d, 1);
    cout << (search ? "true" : "false") << " ";
    for (std::vector<int>::size_type i = 0; i < d.size(); i ++){
        cout << d[i] << " ";
    }
    return 0;
}
