/*
Maximum Sum Combination

You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

Examples:

Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.

Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9

Constraints:
1 ≤ a.size(), b.size(), k ≤ 105
1 ≤ a[i], b[i] ≤ 104
b.size() = a.size()
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> BruteTopKSumPairs(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(a[i] + b[j]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    vector<int> ans;

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

vector<int> OptimalTopKSumPairs(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    priority_queue<pair<int, pair<int, int>>> pq;

    set<pair<int, int>> visited;

    vector<int> ans;

    pq.push({a[0] + b[0], {0, 0}});
    visited.insert({0, 0});

    while (k-- && !pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int sum = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        ans.push_back(sum);

        if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
        {
            pq.push({a[i + 1] + b[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }

        if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
        {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return ans;
}

void printVector(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a1 = {3, 2};
    vector<int> b1 = {1, 4};
    int k1 = 2;

    vector<int> brute1 = BruteTopKSumPairs(a1, b1, k1);
    vector<int> optimal1 = OptimalTopKSumPairs(a1, b1, k1);

    cout << "BruteTopKSumPairs: ";
    printVector(brute1);
    cout << "OptimalTopKSumPairs: ";
    printVector(optimal1);

    vector<int> a2 = {1, 4, 2, 3};
    vector<int> b2 = {2, 5, 1, 6};
    int k2 = 3;

    vector<int> brute2 = BruteTopKSumPairs(a2, b2, k2);
    vector<int> optimal2 = OptimalTopKSumPairs(a2, b2, k2);

    cout << "BruteTopKSumPairs: ";
    printVector(brute2);
    cout << "OptimalTopKSumPairs: ";
    printVector(optimal2);

    return 0;
}