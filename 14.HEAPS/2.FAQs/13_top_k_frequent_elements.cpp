/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]



Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

// Hash Map + Sorting	O(n + m log m)	O(m)
vector<int> topKFrequentElementsI(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (int num : nums)
    {
        mp[num]++;
    }

    vector<pair<int, int>> freq;

    for (auto it : mp)
    {
        freq.push_back({it.first, it.second});
    }

    sort(freq.begin(), freq.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(freq[i].first);
    }

    return ans;
}

// Min Heap	O(n + m log k)	O(m + k)
vector<int> topKFrequentElementsII(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (int num : nums)
    {
        mp[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// Max Heap	O(n + m log m)	O(m)
vector<int> topKFrequentElementsIII(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (auto num : nums)
    {
        mp[num]++;
    }

    priority_queue<pair<int, int>> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// Bucket Sort	O(n) average	O(n)
vector<int> topKFrequentElementsIV(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (auto num : nums)
    {
        mp[num]++;
    }

    vector<vector<int>> bucket(nums.size() + 1);

    for (auto it : mp)
    {
        bucket[it.second].push_back(it.first);
    }

    vector<int> ans;

    for (int i = nums.size(); i >= 1; i--)
    {
        for (int num : bucket[i])
        {
            ans.push_back(num);

            if (ans.size() == k)
            {
                return ans;
            }
        }
    }

    return ans;
}

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;

    vector<int> nums2 = {1};
    int k2 = 1;

    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k3 = 2;

    cout << "Approach I (Hash Map + Sorting):\n";
    printVector(topKFrequentElementsI(nums1, k1));
    cout << "Approach II (Min Heap):\n";
    printVector(topKFrequentElementsII(nums1, k1));
    cout << "Approach III (Max Heap):\n";
    printVector(topKFrequentElementsIII(nums1, k1));
    cout << "Approach IV (Bucket Sort):\n";
    printVector(topKFrequentElementsIV(nums1, k1));

    cout << "\nExample 2:\n";
    cout << "Approach I: ";
    printVector(topKFrequentElementsI(nums2, k2));
    cout << "Approach II: ";
    printVector(topKFrequentElementsII(nums2, k2));
    cout << "Approach III: ";
    printVector(topKFrequentElementsIII(nums2, k2));
    cout << "Approach IV: ";
    printVector(topKFrequentElementsIV(nums2, k2));

    cout << "\nExample 3:\n";
    cout << "Approach I: ";
    printVector(topKFrequentElementsI(nums3, k3));
    cout << "Approach II: ";
    printVector(topKFrequentElementsII(nums3, k3));
    cout << "Approach III: ";
    printVector(topKFrequentElementsIII(nums3, k3));
    cout << "Approach IV: ";
    printVector(topKFrequentElementsIV(nums3, k3));

    return 0;
}