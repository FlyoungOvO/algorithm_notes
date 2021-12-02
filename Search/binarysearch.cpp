#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>&src,int target)
{
    if(src.size() == 0)
        return -1;
    int left = 0,right = src.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2; //Prevent (left + right) overflow
        if(src[mid] == target)
            return mid;
        else if(src[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

