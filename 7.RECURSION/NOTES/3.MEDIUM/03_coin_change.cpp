/*
Coin Change (Count Ways)

Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
Answers are guaranteed to fit into a 32-bit integer. 

Examples:
Input: coins[] = [1, 2, 3], sum = 4
Output: 4
Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].

Input: coins[] = [2, 5, 3, 6], sum = 10
Output: 5
Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].

Input: coins[] = [5, 10], sum = 3
Output: 0
Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.

Constraints:
1 <= sum <= 103
1 <= coins[i] <= 104
1 <= coins.size() <= 103
*/

#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Using Recursion - O(2^sum) time and O(sum) space
int countRec(vector<int> &coins, int sum, int n) {
    if(sum == 0) return 1;
    if(n == 0)  return 0;

    int take = 0;
    if(coins[n - 1] <= sum) {
        take = countRec(coins, sum - coins[n - 1], n);
    }

    int skip = countRec(coins, sum, n - 1);

    return take + skip;
}

int solveCount(vector<int> &coins, int sum, int n, vector<vector<int>> &dp) {
    if(sum == 0)    return 1;
    if(n == 0)  return 0;
    if(dp[n][sum] != -1)   return dp[n][sum];

    int take = 0;
    if(coins[n - 1] <= sum) {
        take = solveCount(coins, sum - coins[n - 1], n, dp);
    }

    int skip = solveCount(coins, sum, n - 1, dp);

    return dp[n][sum] = take + skip;
}

int countDP(vector<int> &coins, int sum, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    
    return solveCount(coins, sum, n, dp);
}

int main() {
    vector<int> coins1 = {1, 2, 3};
    int sum1 = 4;

    cout << "RECURSION: The count is: ";
    cout << countRec(coins1, sum1, coins1.size());

    vector<int> coins2 = {2, 5, 3, 6};
    int sum2 = 10;

    cout << "\nDP: The count is: ";
    cout << countDP(coins2, sum2, coins2.size());

    return 0;
}