/*
Best time to buy and sell stock
Medium

Hints
Company
Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once. 



The stock should be purchased before selling it, and both actions cannot occur on the same day.


Example 1

Input: arr = [10, 7, 5, 8, 11, 9]

Output: 6

Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.

Example 2

Input: arr = [5, 4, 3, 2, 1]

Output: 0

Explanation: In this case, no transactions are made. Therefore, the maximum profit remains 0.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate maximum profit from one buy and one sell
int maxProfit(vector<int>& prices) {

    int minPrice = prices[0];   // Minimum price seen so far
    int maxProfit = 0;          // Maximum profit achievable
    
    // Traverse prices starting from day 1
    for(int i = 1; i < prices.size(); i++){
        
        // Profit if we sell on current day
        int currentProfit = prices[i] - minPrice;
        
        // Update maximum profit
        maxProfit = max(currentProfit, maxProfit);
        
        // Update minimum price for future days
        minPrice = min(prices[i], minPrice);
    }

    return maxProfit;
}

int main() {
    
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit is: " << maxProfit(prices);

    return 0;
}