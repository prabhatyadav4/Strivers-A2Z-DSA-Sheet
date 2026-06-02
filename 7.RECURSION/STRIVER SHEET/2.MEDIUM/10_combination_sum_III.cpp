/*
216. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.


Constraints:
2 <= k <= 9
1 <= n <= 60
*/

#include <iostream>
#include <vector>
using namespace std;

void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &ans)
{

    if (sum == 0 && nums.size() == k)
    {
        ans.push_back(nums);
        return;
    }

    if (sum <= 0 || nums.size() > k)
        return;

    for (int i = last; i <= 9; i++)
    {
        if (i <= sum)
        {

            nums.push_back(i);

            func(sum - i, i + 1, nums, k, ans);

            nums.pop_back();
        }
        else
        {

            break;
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> nums;
    func(n, 1, nums, k, ans);
    return ans;
}

int main()
{

    int k = 3;
    int n = 7;
    vector<vector<int>> result = combinationSum3(k, n);

    cout << "All valid combinations of k are: ";
    for (const auto &combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
