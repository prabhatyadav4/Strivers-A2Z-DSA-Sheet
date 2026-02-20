/*
Koko eating bananas

A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.

Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.

Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.

Example 1

Input: n = 4, nums = [7, 15, 6, 3], h = 8

Output: 5

Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  

Example 2

Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5

Output: 25

Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
int BruteMinimumRateToEatBananas(vector<int> &nums, int h) {
        int n = nums.size();
        int maxPile = 0;
        for(int x : nums){
            maxPile = max(maxPile, x);
        }

        for(int i = 1; i <= maxPile; i++){
            long long totalHours = 0;

            for(int bananas: nums){
                totalHours += (bananas + i - 1) / i;
            }

            if(totalHours <= h){
                return i;
            }
        }

        return -1;
    }

    long long totalHours(vector<int> &nums, int speed){
        long long actualHours = 0;
        for(int &bananas : nums){
            actualHours += (bananas + speed - 1) / speed;
        }

        return actualHours;
    }

    int OptimalMinimumRateToEatBananas(vector<int> &nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;
            int actualHours = totalHours(nums, mid);

            if(actualHours <= h){
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

    vector<int> a = {3, 6, 7, 11};
    int h = 8;

    cout << "The minimum bananas (Brute) is: " << obj.BruteMinimumRateToEatBananas(a, h) << endl;

    cout << "The minimum bananas (Optimal) is: " << obj.OptimalMinimumRateToEatBananas(a, h) << endl;

    return 0;
}