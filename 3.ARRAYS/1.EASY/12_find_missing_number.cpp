/*
Find missing number

Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.

Example 1

Input: nums = [0, 2, 3, 1, 4]

Output: 5

Explanation:

nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]

Example 2

Input: nums = [0, 1, 2, 4, 5, 6]

Output: 3

Explanation:

nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BruteMissingNumber(vector<int>& nums, int n) {

        for(int i = 1; i <= n; i++){
            bool flag = false;
            for(int j = 0; j < n-1; j++){
                if(nums[j] == i){
                    flag = true;
                    break;
                }
            }
            if(!flag) return i;
        }
        return -1;
    }

    int BetterMissingNumber(vector<int> &nums, int n) {
        vector<int> hash(n+1, 0);

        for(int i = 0; i < n-1; i++){
            hash[nums[i]] = 1;
        }

        for(int i = 1; i <= n; i++){
            if(hash[i] == 0)    return i;
        }

        return -1;
    }

    int SumMissingNumber(vector<int> &nums, int n) {
        int expectedSum = n * (n+1) / 2;
        int actualSum = 0;

        for(int x : nums){
            actualSum += x;
        }

        return expectedSum - actualSum;
    }

    int XORMissingNumber(vector<int> &nums, int n) {
        int xor1 = 0, xor2 = 0;
        
        for(int i = 0; i < n-1; i++){
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i+1);
        }

        xor1 = xor1 ^ n;

        return xor1 ^ xor2;
    }
};

int main() {
    Solution obj;
    
    vector<int> arr = {1,2,4,5};

    int n = 5;

    cout << "The missing number (Brute) is: " << obj.BruteMissingNumber(arr, n);
    cout << "\nThe missing number (Better) is: " << obj.BetterMissingNumber(arr, n);
    cout << "\nThe missing number (Optimal-SUM) is: " << obj.SumMissingNumber(arr, n);
    cout << "\nThe missing number (Optimal-XOR) is: " << obj.XORMissingNumber(arr, n);

    return 0;
}