/*
Nearly Sorted

Given an array arr[], where each element is at most k positions away from its correct position in the sorted order. Your task is to restore the sorted order of arr[] by rearranging the elements in place.

Examples:

Input: arr[] = [2, 3, 1, 4], k = 2
Output: [1, 2, 3, 4]
Explanation: All elements are at most k = 2 positions away from their correct positions.
Element 1 moves from index 2 to 0
Element 2 moves from index 0 to 1
Element 3 moves from index 1 to 2
Element 4 stays at index 3

Input: arr[]= [7, 9, 14], k = 1
Output: [7, 9, 14]
Explanation: All elements are already stored in the sorted order.

Constraints:
1 ≤ arr.size(), arr[i] ≤ 106
0 ≤ k < arr.size()
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BruteNearlySorted(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
}

void OptimalNearlySorted(vector<int> &arr, int k)
{
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < min(k + 1, n); i++)
    {
        pq.push(arr[i]);
    }

    int index = 0;

    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    vector<int> arr = {2, 3, 1, 4};
    int k = 2;

    vector<int> bruteArr = arr;
    BruteNearlySorted(bruteArr, k);
    cout << "Brute: ";
    for (int value : bruteArr)
    {
        cout << value << ' ';
    }
    cout << '\n';

    vector<int> optimalArr = arr;
    OptimalNearlySorted(optimalArr, k);
    cout << "Optimal: ";
    for (int value : optimalArr)
    {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}