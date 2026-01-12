/*
Sort an array of 0's 1's and 2's

Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.

The sorting must be done in-place, without making a copy of the original array.


Example 1

Input: nums = [1, 0, 2, 1, 0]

Output: [0, 0, 1, 1, 2]

Explanation:

The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Example 2

Input: nums = [0, 0, 1, 1, 1]

Output: [0, 0, 1, 1, 1]

Explanation:

The nums array in sorted order has 2 zeroes, 3 ones and zero twos
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    // Brute Force (using sort)
    void BruteSort012(vector<int> &arr, int n) {
        sort(arr.begin(), arr.end());
    }

    // Better (Counting method)
    void BetterSort012(vector<int> &arr, int n) {
        int c0 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) c0++;
            else if (arr[i] == 1) c1++;
            else c2++;
        }

        int idx = 0;

        for (int i = 0; i < c0; i++)
            arr[idx++] = 0;

        for (int i = 0; i < c1; i++)
            arr[idx++] = 1;

        for (int i = 0; i < c2; i++)
            arr[idx++] = 2;
    }

    // Optimal (Dutch National Flag Algorithm)
    void OptimalSort012(vector<int>& arr, int n) {
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution obj;

    vector<int> arr = {0, 1, 2, 0, 1, 2};
    int n = arr.size();

    vector<int> a1 = arr, a2 = arr, a3 = arr;

    obj.BruteSort012(a1, n);
    cout << "Brute Sorted: ";

    for (int x : a1) {
        cout << x << " ";
    }

    obj.BetterSort012(a2, n);
    cout << "\nBetter Sorted: ";

    for (int x : a2) {
        cout << x << " ";
    }

    obj.OptimalSort012(a3, n);
    cout << "\nOptimal Sorted: ";

    for (int x : a3) {
        cout << x << " ";
    }

    return 0;
}
