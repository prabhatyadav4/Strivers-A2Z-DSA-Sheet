/*
1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
using namespace std;

int countOdds(const vector<int> &nums, int start, int end)
{
    int oddCount = 0;

    for (int i = start; i <= end; i++)
    {
        if (nums[i] % 2 != 0)
        {
            oddCount++;
        }
    }

    return oddCount;
}

long long BruteNumberOfSubarrays(const vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    long long count = 0;

    for (int start = 0; start < n; start++)
    {

        int oddCount = 0;

        for (int end = start; end < n; end++)
        {
            if (nums[end] % 2 != 0)
            {
                oddCount++;
            }

            if (oddCount == k)
            {
                count++;
            }
        }
    }

    return count;
}

int BetterNumberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    int count = 0;

    for (int start = 0; start < n; start++)
    {
        int oddCount = 0;

        for (int end = start; end < n; end++)
        {

            if (nums[end] % 2 != 0)
            {
                oddCount++;
            }

            if (oddCount == k)
            {
                count++;
            }

            if (oddCount > k)
            {
                break;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int ans1 = BruteNumberOfSubarrays(nums, k);
    cout << "BRUTE: Count of nice subarrays: " << ans1 << endl;

    int ans2 = BetterNumberOfSubarrays(nums, k);
    cout << "BETTER: Count of nice subarrays: " << ans2 << endl;

    return 0;
}