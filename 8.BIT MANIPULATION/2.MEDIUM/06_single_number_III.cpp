/*
260. Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:

Input: nums = [-1,0]
Output: [-1,0]

Example 3:

Input: nums = [0,1]
Output: [1,0]


Constraints:
2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 1. Brute Force

vector<int> singleNumberIII_1(vector<int> &nums)
{
    vector<int> ans;

    for (int num : nums)
    {

        int count = 0;

        for (int ele : nums)
        {
            if (ele == num)
            {
                count++;
            }
        }

        if (count == 1)
        {
            ans.push_back(num);
        }
    }

    return ans;
}

// 2. Hash Map

vector<int> singleNumberIII_2(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    vector<int> ans;

    for (auto &it : freq)
    {
        if (it.second == 1)
        {
            ans.push_back(it.first);
        }
    }

    return ans;
}

// 3. Sorting

vector<int> singleNumberIII_3(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<int> ans;

    int n = nums.size();

    int i = 0;

    while (i < n)
    {
        if (i == n - 1 || nums[i] != nums[i + 1])
        {
            ans.push_back(nums[i]);
            i++;
        }
        else
        {
            i += 2;
        }
    }

    return ans;
}

// 4. Set-Based Approach

vector<int> singleNumberIII_4(vector<int> &nums)
{
    unordered_set<int> st;

    for (int num : nums)
    {
        if (st.count(num))
        {
            st.erase(num);
        }
        else
        {
            st.insert(num);
        }
    }

    return vector<int>(st.begin(), st.end());
}

// 5. XOR Partition Method

vector<int> singleNumberIII_5(vector<int> &nums)
{
    int XOR = 0;

    for (int num : nums)
    {
        XOR ^= num;
    }

    int rsb = XOR & (-XOR);

    int x = 0;
    int y = 0;

    for (int num : nums)
    {
        if (num & rsb)
        {
            x ^= num;
        }
        else
        {
            y ^= num;
        }
    }

    return {x, y};
}

/*
Complexity Comparison:

Approach	            Time	        Space
Brute Force	            O(n²)	        O(1)
Hash Map	            O(n)	        O(n)
Set	                    O(n)	        O(n)
Sorting	                O(n log n)	    O(1)
XOR Partition	        O(n)	        O(1)
*/

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    vector<int> ans1 = singleNumberIII_1(nums);
    vector<int> ans2 = singleNumberIII_2(nums);
    vector<int> ans3 = singleNumberIII_3(nums);
    vector<int> ans4 = singleNumberIII_4(nums);
    vector<int> ans5 = singleNumberIII_5(nums);

    cout << "Brute Force: ";
    cout << ans1[0] << " " << ans1[1] << endl;

    cout << "Hash Map: ";
    cout << ans2[0] << " " << ans2[1] << endl;

    cout << "Sorting: ";
    cout << ans3[0] << " " << ans3[1] << endl;

    cout << "Set: ";
    cout << ans4[0] << " " << ans4[1] << endl;

    cout << "XOR Partition: ";
    cout << ans5[0] << " " << ans5[1] << endl;

    return 0;
}