/*
55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false

Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(const vector<int> &nums)
{
    int n = nums.size();
    int farthest = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > farthest)
        {
            return false;
        }

        farthest = max(farthest, i + nums[i]);

        if (farthest >= n - 1)
        {
            return true;
        }
    }

    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Can You Reach the Last Index?: " << (canJump(nums) ? "Yes" : "No") << endl;

    return 0;
}

/*
Jump Game

Problem statement

You have been given an array 'ARR' of ‘N’ integers. You have to return the minimum number of jumps needed to reach the last index of the array i.e ‘N - 1’.

From index ‘i’, we can jump to an index ‘i + k’ such that 1<= ‘k’ <= ARR[i] .

'ARR[i]' represents the maximum distance you can jump from the current index.

If it is not possible to reach the last index, return -1.

Note:
Consider 0-based indexing.
Example:
Consider the array 1, 2, 3, 4, 5, 6
We can Jump from index 0 to index 1
Then we jump from index 1 to index 2
Then finally make a jump of 3 to reach index N-1

There is also another path where
We can Jump from index 0 to index 1
Then we jump from index 1 to index 3
Then finally make a jump of 2 to reach index N-1

So multiple paths may exist but we need to return the minimum number of jumps in a path to end which here is 3.

Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1:
5
2 3 1 1 4

Sample Output 1:
2

Explanation of sample input 1 :

Consider the above figure:
We are initially at index 0, ARR[0] is 2 which represents we can jump a maximum of 2 steps.

We jump 1 index from 0 to 1. At index 1, 'ARR[1]' is 3 which represents we can jump a maximum of 3 steps so we jump 3 indices from 1 to 4 to reach the last index. Hence we return 2.

It can be proved that the end can't be reached in less than 2.

Sample Input 2:
5
3 2 1 0 1

Sample Output 2:
-1

Constraints:
1 <= N <= 10 ^ 4
1 <= ARR[i] <= 10 ^ 4

Where ‘ARR[i]’ denotes the ‘i-th’ element of the ‘ARR’.

Time limit: 1 sec.
*/

// int minJumps(vector<int>& arr) {
//     int n = arr.size();

//     if (n <= 1)
//         return 0;

//     if (arr[0] == 0)
//         return -1;

//     int jumps = 0;
//     int currentEnd = 0;
//     int farthest = 0;

//     for (int i = 0; i < n - 1; i++) {

//         farthest = max(farthest, i + arr[i]);

//         if (i == currentEnd) {

//             if (farthest <= i)
//                 return -1;

//             jumps++;
//             currentEnd = farthest;

//             if (currentEnd >= n - 1)
//                 return jumps;
//         }
//     }

//     return -1;
// }