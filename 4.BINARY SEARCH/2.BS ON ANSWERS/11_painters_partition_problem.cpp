/*
Painter's Partition

You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

Each painter paints only contiguous segments of boards.
No board can be split between painters.
The goal is to minimize the time to paint all boards.

Return the minimum time required to paint all boards modulo 10000003.

Example 1

Input: A = 2, B = 5, C = [1, 10]

Output: 50

Explanation:

Painter 1 paints board 0 (length = 1), time = 5
Painter 2 paints board 1 (length = 10), time = 50
Max time = 50
Return 50 % 10000003 = 50
Example 2

Input: A = 10, B = 1, C = [1, 8, 11, 3]

Output: 11

Explanation:

Assign each board to a different painter
Max time = max(1, 8, 11, 3) = 11
Return 11 % 10000003 = 11
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
    public: 
    int countPainters(vector<int> &boards, int time) {
        int n = boards.size();
        int painters = 1; 
        long long boardsPainter = 0;

        for (int i = 0; i < n; i++) {
            if (boardsPainter + boards[i] <= time) {
                boardsPainter += boards[i];
            } else {
                painters++;
                boardsPainter = boards[i];
            }
        }
        return painters;
    }

    int BruteLargestMinDistance(vector<int> &boards, int k) {
        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0); 

        for (int time = low; time <= high; time++) {
            if (countPainters(boards, time) <= k) {
                return time;
            }
        }
        return low;
    }

    int OptimalLargestMinDistance(vector<int> &boards, int k) {
        int low = *max_element(boards.begin(), boards.end());      
        int high = accumulate(boards.begin(), boards.end(), 0);    

        int result = high;

        while (low <= high) {
            int mid = (low + high) / 2;  
            int painters = countPainters(boards, mid);

            if (painters > k) {
                low = mid + 1; 
            } else {
                result = mid; 
                high = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    int result1 = obj.BruteLargestMinDistance(boards, k);
    cout << "The largest minimum distance (Brute) is: " << result1 << "\n";

    int result2 = obj.OptimalLargestMinDistance(boards, k);
    cout << "The largest minimum distance (Brute) is: " << result2 << "\n";

    return 0;
}