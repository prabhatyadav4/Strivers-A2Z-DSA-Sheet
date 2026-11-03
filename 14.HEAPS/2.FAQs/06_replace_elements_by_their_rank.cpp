/*
1331. Rank Transform of an Array

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.


Example 1:
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

Example 2:
Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.

Example 3:
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]


Constraints:
0 <= arr.length <= 105
-109 <= arr[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// Sorting + HashMap

vector<int> arrayRankTransformI(vector<int> &arr)
{
    vector<int> temp = arr;

    sort(temp.begin(), temp.end());

    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    unordered_map<int, int> mp;

    for (int i = 0; i < temp.size(); i++)
    {
        mp[temp[i]] = i + 1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = mp[arr[i]];
    }

    return arr;
}

// Heap + HashMap

vector<int> arrayRankTransformII(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : arr)
    {
        pq.push(num);
    }

    unordered_map<int, int> mp;

    int rank = 0;

    while (!pq.empty())
    {
        int num = pq.top();
        pq.pop();

        if (mp.find(num) == mp.end())
        {
            rank++;
            mp[num] = rank;
        }
    }

    vector<int> ans;

    for (int num : arr)
    {
        ans.push_back(mp[num]);
    }

    return ans;
}

int main()
{
    vector<int> input = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> sortedResult = input;
    vector<int> heapResult = input;

    arrayRankTransformI(sortedResult);
    heapResult = arrayRankTransformII(heapResult);

    cout << "Sorting + HashMap: ";
    for (int rank : sortedResult)
    {
        cout << rank << " ";
    }

    cout << "\nHeap + HashMap: ";
    for (int rank : heapResult)
    {
        cout << rank << " ";
    }
    cout << '\n';
}