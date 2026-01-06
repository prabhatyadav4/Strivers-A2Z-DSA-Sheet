/*
Check Sorted Array

Problem statement
You have been given an array ‘a’ of ‘n’ non-negative integers.
You have to check whether the given array is sorted in the non-decreasing order or not.
Your task is to return 1 if the given array is sorted. Else, return 0.

Example :
Input: ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
Output: 1

The given array is sorted in non-decreasing order; hence the answer will be 1.
*/

#include <iostream>
#include <vector>
using namespace std;

int isSorted(int n, vector<int> a) {
    // Write your code here.
    for(int i = 1; i < n; i++){

        if(a[i] >= a[i-1]){

        }
        
        else {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr = {1,2,2,3,3,4};
    
    if(isSorted(arr.size(), arr) == true){
        cout << "The array is sorted.";
    }
    else {
        cout << "The array is not sorted.";
    }
}