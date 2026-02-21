/*
Find the smallest divisor

Given an array of integers nums and an integer limit as the threshold value, find the smallest positive integer divisor such that upon dividing all the elements of the array by this divisor, the sum of the division results is less than or equal to the threshold value.

After dividing each element by the chosen divisor, take the ceiling of the result (i.e., round up to the next whole number).

Example 1

Input: nums = [1, 2, 3, 4, 5], limit = 8

Output: 3

Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 

The sum is 9(1 + 1 + 2 + 2 + 3) if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.

Example 2

Input: nums = [8,4,2,3], limit = 10

Output: 2

Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9 (4+2+1+2) <= 10 as the answer. So, 2 is the answer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumByD(vector<int>& nums, int div){
        int sum = 0;
        for(int num : nums){
            sum += (num + div - 1) / div;
        }

        return sum;
    }

    int BruteSmallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        for(int d = 1; d <= maxi; d++){
            if(sumByD(nums, d) <= threshold){
                return d;
            }
        }

        return -1;
    }

    int OptimalSmallestDivisor(vector<int>& nums, int threshold){
        if(threshold < nums.size())   return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(sumByD(nums, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
    
};

int main() {
    Solution obj;

    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;

    int result1 = obj.BruteSmallestDivisor(arr, limit);
    cout << "The minimum divisor (Brute) is: " << result1 << endl;

    int result2 = obj.OptimalSmallestDivisor(arr, limit);
    cout << "The minimum divisor (Optimal) is: " << result2 << endl;

    return 0;
}