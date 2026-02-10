/*
Count Inversions

Given an integer array nums. Return the number of inversions in the array.

Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

It indicates how close an array is to being sorted.

A sorted array has an inversion count of 0.

An array sorted in descending order has maximum inversion.

Example 1

Input: nums = [2, 3, 7, 1, 3, 5]

Output: 5

Explanation:

The responsible indexes are:

nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3

nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3

nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3

nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4

nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

Example 2

Input: nums = [-10, -5, 6, 11, 15, 17]

Output: 0

Explanation:

nums is sorted, hence no inversions present.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 

    long long BruteNumberOfInversions(vector<int> nums) {
        int n = nums.size();
        long long count = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] > nums[j])   count++;
            }
        }

        return count;
    }

    long long countAndMerge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> left(n1), right(n2);

        for(int i = 0; i < n1; i++) left[i] = arr[l + i];
        for(int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];

        long long res = 0;
        int i = 0, j = 0, k = l;

        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                res += (n1 - i);   // key inversion count
            }
        }

        while(i < n1) arr[k++] = left[i++];
        while(j < n2) arr[k++] = right[j++];

        return res;
    }

    long long countInv(vector<int>& arr, int l, int r) {
        long long res = 0;
        if(l < r) {
            int m = l + (r - l) / 2;
            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);
            res += countAndMerge(arr, l, m, r);
        }
        return res;
    }

    long long OptimalNumberOfInversions(vector<int> nums) {
        int n = nums.size();
        return countInv(nums, 0, n-1);
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2,4,1,3,5};

    long long result1 = obj.BruteNumberOfInversions(arr);

    cout << "The number of inversions (Brute) in the array are: " << result1;

    long long result2 = obj.OptimalNumberOfInversions(arr);

    cout << "\nThe number of inversions (Optimal) in the array are: " << result2;

    return 0;
}