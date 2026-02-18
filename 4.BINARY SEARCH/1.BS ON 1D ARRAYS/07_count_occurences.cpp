/*
Count Occurrences in a Sorted Array

You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.

Return the count of occurrences of target in the array.

Example 1

Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1

Output: 3

Explanation: The number 1 appears 3 times in the array.

Example 2

Input: arr = [5, 5, 5, 5, 5, 5], target = 5

Output: 6

Explanation: All elements in the array are 5, so the target appears 6 times.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    int firstOccurence(vector<int> &nums, int n, int target){
        int low = 0, high = n - 1;
        int first = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return first;
    }

    int lastOccurence(vector<int> &nums, int n, int target){
        int low = 0, high = n - 1;
        int last = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return last;
    }

    vector<int> FirstAndLastOccurence(vector<int> &nums, int target){
        int n = nums.size();
        int first = firstOccurence(nums, n, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurence(nums, n, target);

        return {first, last};
    }

    int countOccurrences(vector<int>& arr, int target) {
        vector<int> ans = FirstAndLastOccurence(arr, target);
        if(ans[0] == -1)    return 0;
        return (ans[1] - ans[0]) + 1;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int result = obj.countOccurrences(arr, target);
    cout << "The target appears " << result << " times.";

    return 0;
}