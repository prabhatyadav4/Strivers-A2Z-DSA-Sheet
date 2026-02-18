/*
Find square root of a number

Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

Example 1

Input: n = 36

Output: 6

Explanation: 6 is the square root of 36.

Example 2

Input: n = 28

Output: 5

Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int BruteFloorSqrt(int n){
        if(n < 2)   return n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if((long long)i * i <= n){
                ans = i;
            }
            else{
                break;
            }
        }

        return ans;
    }

    int OptimalFloorSqrt(int n){
        if(n < 2)   return n;
        int left = 1, right = n / 2;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(mid * mid <= n)  left = mid + 1;
            else    right = mid - 1;
        }

        return right;
    }
};

int main() {
    Solution obj;

    int n = 27;

    int result1 = obj.BruteFloorSqrt(n);
    cout << "The square root (Brute) of n is: " << result1 << endl;

    int result2 = obj.OptimalFloorSqrt(n);
    cout << "The square root (Optimal) of n is: " << result2 << endl;

    return 0;
}