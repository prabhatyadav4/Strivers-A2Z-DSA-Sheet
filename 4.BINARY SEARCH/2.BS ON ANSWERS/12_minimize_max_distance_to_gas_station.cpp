/*
Minimize Max Distance to Gas Station

Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.

The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.

Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.

Find the minimum value of dist.

Your answer will be accepted if it is within 1e-6 of the true value.

Example 1

Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10

Output: 0.50000

Explanation:

One of the possible ways to place 10 gas stations is [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10].

Thus the maximum difference between adjacent gas stations is 0.5.

Hence, the value of dist is 0.5.

It can be shown that there is no possible way to add 10 gas stations in such a way that the value of dist is lower than this.

Example 2

Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1

Output: 1.00000

Explanation:

One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
New Gas Station is at 11.
Thus the maximum difference between adjacent gas stations is still 1.
Hence, the value of dist is 1.
It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this. 
*/

#include <bits/stdc++.h>
using namespace std;

// Class to solve the gas station placement problem
class GasStationSolver {
public:
    // Function to minimize the maximum distance after placing k gas stations
    long double minimiseMaxDistance(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // howMany[i]: extra stations between arr[i] and arr[i+1]

        // Place k gas stations one at a time
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            long double maxSection = -1;
            int maxInd = -1;

            // Find the segment with the current largest section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength = diff / (howMany[i] + 1.0);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            // Add a gas station in the largest segment
            howMany[maxInd]++;
        }

        // Find the final maximum distance after placing all gas stations
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1.0);
            maxAns = max(maxAns, sectionLength);
        }

        return maxAns;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    GasStationSolver solver;
    long double ans = solver.minimiseMaxDistance(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}