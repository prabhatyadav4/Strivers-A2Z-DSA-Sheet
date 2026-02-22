/*
Capacity to Ship Packages Within D Days

You are given an array weights where weights[i] represents the weight of the i-th package on a conveyor belt. All the packages must be shipped in the order given from one port to another within days days.

Each day, the ship can carry a contiguous sequence of packages, as long as the total weight does not exceed its maximum capacity.

Your task is to find the minimum possible capacity of the ship so that all packages can be shipped within the given number of days.

Example 1

Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5

Output: 15

Explanation:

Minimum ship capacity = 15. One way to ship in 5 days:

Day 1: 1 + 2 + 3 + 4 + 5 = 15
Day 2: 6 + 7 = 13
Day 3: 8
Day 4: 9
Day 5: 10


No day exceeds capacity 15 and all packages are shipped in order in 5 days.

Example 2

Input: weights = [3, 2, 2, 4, 1, 4], days = 3

Output: 6

Explanation:

One possible division with capacity 6:

Day 1: 3 + 2 = 5
Day 2: 2 + 4 = 6
Day 3: 1 + 4 = 5


All packages shipped in order within 3 days.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity){
        int days = 1;
        int currentLoad = 0;

        for(int i = 0; i < weights.size(); i++){
            if(currentLoad + weights[i] > capacity){
                days++;
                currentLoad = weights[i];
            }
            else{
                currentLoad += weights[i];
            }
        }

        return days;
    }

    int BruteShipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0LL);

        for(int capacity = low; capacity <= high; capacity++){
            if(daysNeeded(weights, capacity) <= days){
                return capacity;
            }
        }

        return high;
    }

    int OptimalShipWithinDays(vector<int>& weights, int days){
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0LL);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int noOfDays = daysNeeded(weights, mid);
            if(noOfDays <= days){
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

    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;

    int result1 = obj.BruteShipWithinDays(weights, days);
    cout << "The least weight capacity (Brute) of the ship is: " << result1 << endl;

    int result2 = obj.OptimalShipWithinDays(weights, days);
    cout << "The least weight capacity (Optimal) of the ship is: " << result2 << endl;

    return 0;
}