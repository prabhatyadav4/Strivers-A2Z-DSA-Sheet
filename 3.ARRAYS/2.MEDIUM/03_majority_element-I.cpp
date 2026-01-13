/*
Majority Element-I

Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.


Example 1

Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]

Output: 7

Explanation:

The number 7 appears 5 times in the 9 sized array

Example 2

Input: nums = [1, 1, 1, 2, 1, 2]

Output: 1

Explanation:

The number 1 appears 4 times in the 6 sized array
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int BruteMajorityElement(vector<int>& arr){
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int count = 0; 
            for(int j = 0; j < n; j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count > n/2){
                return arr[i];
            }
        }
        return -1;
    }

    int BetterMajorityElement(vector<int>& arr){
        int n = arr.size();

        unordered_map<int, int> countMap;

        for(int num : arr){
            countMap[num]++;
            
            if(countMap[num] > n/2){
                return num;
            }
        }
        return -1;
    }

    int OptimalMajorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;

        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt --;
            }
        }

        int cnt1 = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el)   cnt1++;
        }

        if(cnt1 > (nums.size() / 2)) {
            return el;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {7, 0, 0, 1, 7, 7, 2, 7, 7};

    int brute = obj.BruteMajorityElement(nums);
    int better = obj.BetterMajorityElement(nums);
    int optimal = obj.OptimalMajorityElement(nums);

    cout << "Brute Force Majority Element: " << brute << endl;
    cout << "Better Majority Element: " << better << endl;
    cout << "Optimal Majority Element: " << optimal << endl;

    return 0;
}
