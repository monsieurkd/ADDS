#include "RecursiveBinarySearch.h"
#include <vector>


bool binarySearch(std::vector<int> &list, int n,int  start,int  end){
    if(start > end){
        return false;
    }
    int mid = (start+end)/2;
    if (list[mid] == n){
        return true;
    }else if (list[mid] > n){
        return binarySearch(list, n, start, mid-1);
    }else{
        return binarySearch(list, n, mid+1, end);
    }
};


bool RecursiveBinarySearch::search(std::vector<int> list, int n){
    
    return binarySearch(list, n, 0,list.size()-1) ;
};


