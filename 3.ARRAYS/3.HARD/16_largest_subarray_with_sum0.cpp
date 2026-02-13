/*
Largest Subarray with Sum 0

You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0.

Return the length of such a subarray. If no such subarray exists, return 0.

Example 1

Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]

Output: 5

Explanation:

The subarray [-2, 2, -8, 1, 7] sums up to 0 and has the maximum length among all such subarrays.

Example 2

Input: arr = [2, 10, 4]

Output: 0

Explanation:

There is no subarray whose elements sum to 0.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int BruteMaxLen(vector<int>& arr) {
        int maxLen = 0;
        unordered_map<int, int> sumIndexMap;
        int sum = 0;

        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];

            if(sum == 0){
                maxLen = i+1;
            }

            else if(sumIndexMap.find(sum) !=sumIndexMap.end()){
                maxLen = max(maxLen, i - sumIndexMap[sum]);
            }

            else{
                sumIndexMap[sum] = i;
            }
        }

        return maxLen;
    }

    int OptimalMaxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int maxi = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            if(sum == 0){
                maxi = i + 1;
            }
            else{
                if(mpp.find(sum) != mpp.end()){
                    maxi = max(maxi, i - mpp[sum]);
                }
                else{
                    mpp[sum] = i;
                }
            }
        }

        return maxi;
    }
};

int main() {
  Solution obj;

  vector<int> A = {9, -3, 3, -1, 6, -5};
  
  int result1 = obj.BruteMaxLen(A);
  
  cout << "The length of the longest subarray (Brute) with sum zero is: " << result1 << endl;

  int result2 = obj.OptimalMaxLen(A);
  
  cout << "The length of the longest subarray (Brute) with sum zero is: " << result2 << endl;
  
  return 0;
}