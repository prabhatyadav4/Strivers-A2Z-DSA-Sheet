/*
Find Nth root of a number

Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.


Example 1

Input: N = 3, M = 27

Output: 3

Explanation: The cube root of 27 is equal to 3.

Example 2

Input: N = 4, M = 69

Output:-1

Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:

    int BruteNthRoot(int n, int m) {
       for(int i = 0; i < m; i++){
            long long power = pow(i, n);
            if(power == m)  return i;
            if(power > m)   break;
       }
       return -1;
    }

    int OptimalNthRoot(int n, int m) {
       int low = 1, high = m;
       while(low <= high){
        int mid = low + (high - low) / 2;
        long long ans = 1;
        for(int i = 0; i < n; i++){
            ans *= mid;
            if(ans > m) break;
        }
        if(ans == m)    return mid;
        if(ans < m) low = mid + 1;
        else    high = mid - 1;
       }

       return -1;
    }
};

int main() {
    Solution obj;
    int n = 3, m = 27;

    cout << "Nth Root (Brute): " << obj.BruteNthRoot(n, m) << endl;
    cout << "Nth Root (Optimal): " << obj.OptimalNthRoot(n, m) << endl;

    return 0;
}