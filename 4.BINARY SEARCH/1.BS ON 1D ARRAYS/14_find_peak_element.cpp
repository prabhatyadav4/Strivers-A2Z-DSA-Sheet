/*
Find peak element

Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors.

Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].

Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note:

As there can be many peak values, "true" is given as output if the returned index is a peak number, otherwise "false".

Example 1

Input : arr = [1, 2, 3, 4, 5, 6, 7, 8, 5, 1]

Output: 7

Explanation: In this example, there is only 1 peak that is at index 7.

Example 2

Input : arr = [1, 2, 1, 3, 5, 6, 4]

Output: 1

Explanation: In this example, there are 2 peak numbers at indices 1 and 5. We can consider any of them.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BetterFindPeakElement(vector<int> &nums) {
      int n = nums.size();
      for(int i = 0; i < n; i++){
        if(((i == 0) || nums[i - 1] < nums[i]) && ((i == n - 1) || nums[i] > nums[i + 1])){
            return i;
        }
      }

      return -1;
    }

    int Optimal1FindPeakElement(vector<int> &nums){
        int n = nums.size();
        if (n == 1) return 0;
        if(nums[0] > nums[1])   return 0;
        if(nums[n - 1] > nums[n - 2])   return n - 1; 

        int low = 1, high = n - 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(nums[mid] > nums[mid - 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }

    int Optimal2FindPeakElement(vector<int> &nums){
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid + 1])   high = mid;
            else    low = mid + 1;
        }

        return low;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 20, 4, 1, 0};
    int index1 = obj.BetterFindPeakElement(nums);
    cout << "Peak at index (Brute): " << index1 << " with value: " << nums[index1] << endl;

    int index2 = obj.Optimal1FindPeakElement(nums);
    cout << "Peak at index (Optimal1): " << index2 << " with value: " << nums[index2] << endl;

    int index3 = obj.Optimal2FindPeakElement(nums);
    cout << "Peak at index (Optimal2): " << index3 << " with value: " << nums[index3] << endl;

    return 0;
}