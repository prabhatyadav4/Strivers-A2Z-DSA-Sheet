/*
137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 1. Brute Force (Nested Loops)

int singleNumberII_1(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }

        if (count == 1)
        {
            return nums[i];
        }
    }

    return -1;
}

// 2. Hash Map

int singleNumberII_2(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (auto &it : freq)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }

    return -1;
}

// 3. Sorting

int singleNumberII_3(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 1; i += 3)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }

    return nums[n - 1];
}

// 4. Mathematical Trick

/*
Key Observation:

Let:

uniqueSum = sum of all distinct numbers
totalSum = sum of all numbers in the array
x = single number (appears once)

Suppose the distinct numbers are:

a, b, c, x

where a, b, c appear 3 times.

Then:

uniqueSum = a + b + c + x   and     totalSum = 3a + 3b + 3c + x

Now multiply uniqueSum by 3:

3 * uniqueSum   = 3a + 3b + 3c + 3x

Subtract totalSum:

3 * uniqueSum - totalSum
= (3a + 3b + 3c + 3x) - (3a + 3b + 3c + x) = 2x

Therefore:  x = (3 * uniqueSum - totalSum) / 2

which is exactly:   return (3 * uniqueSum - totalSum) / 2;
*/

int singleNumberII_4(vector<int> &nums)
{
    unordered_set<int> st;

    long long totalSum = 0;
    long long uniqueSum = 0;

    for (int num : nums)
    {
        totalSum += num;

        if (st.find(num) == st.end())
        {
            st.insert(num);
            uniqueSum += num;
        }
    }

    return (3 * uniqueSum - totalSum) / 2;
}

// 5. Bit Counting

int singleNumberII_5(vector<int> &nums)
{
    int ans = 0;

    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;

        for (int num : nums)
        {
            if (num & (1 << bit))
            {
                count++;
            }
        }

        if (count % 3)
        {
            ans |= (1 << bit);
        }
    }

    return ans;
}

// 6. Bit Manipulation State Machine

int singleNumberII_6(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;

    for (int num : nums)
    {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }

    return ones;
}

/*
Approach	                    Time	        Space
Brute Force	                    O(n²)	        O(1)
Hash Map	                    O(n)	        O(n)
Sorting	                        O(n log n)	    O(1)
Mathematical	                O(n)	        O(n)
Bit Counting	                O(n)	        O(1)
Ones/Twos State Machine	        O(n)	        O(1)
*/

int main()
{
    vector<int> nums = {2, 2, 1, 4, 4};

    cout << "The single element is: " << singleNumberII_1 << endl;
    cout << "The single element is: " << singleNumberII_2 << endl;
    cout << "The single element is: " << singleNumberII_3 << endl;
    cout << "The single element is: " << singleNumberII_4 << endl;
    cout << "The single element is: " << singleNumberII_5 << endl;
    cout << "The single element is: " << singleNumberII_6 << endl;

    return 0;
}