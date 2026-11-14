/*
742. Second Highest Occurring Element

Given an array of n integers, find the second most frequent element in it.

If there are multiple elements that appear second most frequent times, find the smallest of them.

If second most frequent element does not exist return -1.

Example 1:
Input: arr = [1, 2, 2, 3, 3, 3]

Output: 2

Explanation:

The number 2 appears the second most (2 times) and number 3 appears the most(3 times).

Example 2:
Input: arr = [4, 4, 5, 5, 6, 7]

Output: 6

Explanation:

Both 6 and 7 appear second most times, but 6 is smaller.

Constraints:
1 <= n <= 105
1 <= arr[i] <= 104
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int secondMostFrequentElement(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    int maxFreq = 0;
    int secondMaxFreq = 0;

    for (auto it : freq)
    {
        int element = it.first;
        int count = it.second;

        if (count > maxFreq)
        {
            secondMaxFreq = maxFreq;
            maxFreq = count;
        }
        else if (count < maxFreq && count > secondMaxFreq)
        {
            secondMaxFreq = count;
        }
    }

    if (secondMaxFreq == 0)
    {
        return -1;
    }

    int ans = INT_MAX;

    for (auto it : freq)
    {
        if (it.second == secondMaxFreq)
        {
            ans = min(ans, it.first);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 3};

    cout << "The second most frequent element is: " << secondMostFrequentElement(nums);

    return 0;
}