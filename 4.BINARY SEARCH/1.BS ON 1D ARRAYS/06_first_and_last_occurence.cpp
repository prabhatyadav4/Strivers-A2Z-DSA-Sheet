/*
First and last occurrence

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].

Example 1

Input: nums = [5, 7, 7, 8, 8, 10], target = 8

Output: [3, 4]

Explanation:The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]

Example 2

Input: nums = [5, 7, 7, 8, 8, 10], target = 6

Output: [-1, -1]

Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> BruteSearchRange(vector<int> &nums, int target) {
        int first = -1, last = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if(first == -1)     first = i;
                last = i;
            }
        }
        return {first, last};
    }

    int lowerBound(vector<int> &nums, int n, int target){
        int low = 0, high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int> &nums, int n, int target){
        int low = 0, high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> BetterSearchRange(vector<int> &nums, int target){
        int n = nums.size();
        int lb = lowerBound(nums, n, target);
        if(lb == n || nums[lb] != target)   return {-1, -1};

        return {lb, upperBound(nums, n, target) - 1};
    }

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

    vector<int> OptimalSearchRange(vector<int> &nums, int target){
        int n = nums.size();
        int first = firstOccurence(nums, n, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurence(nums, n, target);

        return {first, last};
    }
};

int main() {
    Solution obj;

    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result1 = obj.BruteSearchRange(arr, target);
    cout << "The starting and ending position of the target (Brute) is: ";
    cout << "[" << result1[0] << " , " << result1[1] << "]" << endl;

    vector<int> result2 = obj.BetterSearchRange(arr, target);
    cout << "The starting and ending position of the target (Better) is: ";
    cout << "[" << result2[0] << " , " << result2[1] << "]" << endl;

    vector<int> result3 = obj.OptimalSearchRange(arr, target);
    cout << "The starting and ending position of the target (Optimal) is: ";
    cout << "[" << result3[0] << " , " << result3[1] << "]" << endl;

    return 0;
}