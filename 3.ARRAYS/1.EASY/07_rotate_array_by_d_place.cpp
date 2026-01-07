/*
Left Rotate Array by K Places

Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.

Example 1

Input: nums = [1, 2, 3, 4, 5, 6], k = 2

Output: nums = [3, 4, 5, 6, 1, 2]

Explanation:

rotate 1 step to the left: [2, 3, 4, 5, 6, 1]

rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]

Example 2

Input: nums = [3, 4, 1, 5, 3, -5], k = 8

Output: nums = [1, 5, 3, -5, 3, 4]

Explanation:

rotate 1 step to the left: [4, 1, 5, 3, -5, 3]

rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]

rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]

rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]

rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]

rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]

rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]

rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int> &arr, int k){
    int n = arr.size();

    if(n == 0)  return;

    k = k % n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

// OR

void rotateArrayByK(int arr[], int k, int n){
    
    if(n == 0)  return;

    k = k % n;

    int temp[k];
    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }

    for(int i = k; i < n; i++){
        arr[i-k] = arr[i];
    }

    for(int i = n-k; i < n; i++){
        arr[i] = temp[i - (n-k)];
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    int nums[7] = {2,3,4,5,6,7,8};
    int n = 7;
    int k = 3;
    
    rotateArray(arr, k);
    rotateArrayByK(nums, n-k, n);

    cout << "Rotated Array: ";
    for(int x : arr){
        cout << x << " ";
    }

    cout << "\nAnother Rotated Array : ";
    for(int i = 0; i < 7; i++){
        cout << nums[i] << " ";
    }

    return 0;
}