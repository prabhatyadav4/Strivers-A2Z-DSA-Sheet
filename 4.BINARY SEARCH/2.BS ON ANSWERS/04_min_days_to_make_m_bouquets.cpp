/*
Minimum days to make M bouquets

Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.

Example 1

Input: n = 8, nums = [7, 7, 7, 7, 13, 11, 12, 7], m = 2, k = 3

Output: 12

Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2

Input: n = 5, nums = [1, 10, 3, 10, 2], m = 3, k = 2

Output: -1

Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &bloomDay, int day, int m, int k){
        int count = 0;
        int bouquets = 0;

        for(int bloom : bloomDay){
            if(bloom <= day){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }

        return bouquets >= m;
    }

    int BruteMinDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;
        if(totalFlowers > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        for(int day = low; day <= high; day++){
            if(isPossible(bloomDay, day, m, k)){
                return day;
            }
        }

        return -1;
    }

    int OptimalMinDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;
        if(totalFlowers > bloomDay.size())   return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(bloomDay, mid, m, k)){
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

    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2;
    int k = 3;

    int result1 = obj.BruteMinDays(bloomDay, m, k);
    if(result1 == -1){
        cout << "Brute: We cannot make m bouquets" << endl;
    }
    else{
        cout << "Brute: We can make m bouquets on day: " << result1 << endl;
    }

    int result2 = obj.OptimalMinDays(bloomDay, m, k);
    if(result2 == -1){
        cout << "Optimal: We cannot make m bouquets" << endl;
    }
    else{
        cout << "Optimal: We can make m bouquets on day: " << result2 << endl;
    }

    return 0;
}