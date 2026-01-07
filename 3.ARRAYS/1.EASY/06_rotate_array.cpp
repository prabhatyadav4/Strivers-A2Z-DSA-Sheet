/*
Left Rotate Array by One

Given an integer array nums, rotate the array to the left by one.

Note: There is no need to return anything, just modify the given array.

Example 1

Input: nums = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

Explanation:

Initially, nums = [1, 2, 3, 4, 5]

Rotating once to left -> nums = [2, 3, 4, 5, 1]

Example 2

Input: nums = [-1, 0, 3, 6]

Output: [0, 3, 6, -1]

Explanation:

Initially, nums = [-1, 0, 3, 6]

Rotating once to left -> nums = [0, 3, 6, -1]
*/

#include <iostream>
#include <vector>
using namespace std;

void rotateArrayByOne(vector<int> &arr, int n){
    if(n == 0)  return;
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main() {
    vector<int> arr = {1,2,3,4,5};

    rotateArrayByOne(arr, arr.size());

    cout << "Rotated Array: ";
    for(int x : arr){
        cout << x << " ";
    }

    return 0;
} 