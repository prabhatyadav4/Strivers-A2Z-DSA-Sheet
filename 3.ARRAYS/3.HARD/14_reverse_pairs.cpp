/*
Reverse Pairs

Given an integer array nums. Return the number of reverse pairs in the array.

An index pair (i, j) is called a reverse pair if:

0 <= i < j < nums.length

nums[i] > 2 * nums[j]

Example 1

Input: nums = [6, 4, 1, 2, 7]

Output: 3

Explanation:

The reverse pairs are:

(0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1

(0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2

(1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

Example 2

Input: nums = [5, 4, 4, 3, 3]

Output: 0

Explanation:

No pairs satisfy both the conditons.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BruteReversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] > 2*nums[j])     count++;
            }
        }

        return count;
    }

    int merging(vector<int>& arr, int low, int mid, int high) {
    
        int count = 0, j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;
        int count = mergeSort(arr, low, mid) + 
                    mergeSort(arr, mid + 1, high) +
                    merging(arr, low, mid, high);

        return count;
    }

    int OptimalReversePairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution obj;

    vector<int> arr = {40,25,19,12,9,6,2};

    int result1 = obj.BruteReversePairs(arr);

    cout << "The number of reverse pairs in the array (Brute) is: " << result1 << endl;

    int result2 = obj.OptimalReversePairs(arr);

    cout << "The number of reverse pairs in the array (Optimal) is: " << result2 << endl;

    return 0;
}