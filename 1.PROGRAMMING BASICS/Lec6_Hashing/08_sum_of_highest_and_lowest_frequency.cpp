/*
749. Sum of Highest and Lowest Frequency

Given an array of n integers, find the sum of the frequencies of the highest occurring number and lowest occurring number.

Example 1:
Input: arr = [1, 2, 2, 3, 3, 3]

Output: 4

Explanation: The highest frequency is 3 (element 3), and the lowest frequency is 1 (element 1). Their sum is 3 + 1 = 4.

Example 2:
Input: arr = [4, 4, 5, 5, 6]

Output: 3

Explanation: The highest frequency is 2 (elements 4 and 5), and the lowest frequency is 1 (element 6). Their sum is 2 + 1 = 3.

Constraints:
1 <= n <= 105
1 <= arr[i] <= 104
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumHighestAndLowestFreq(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    int maxFreq = 0;
    int minFreq = nums.size();

    for (auto it : freq)
    {
        maxFreq = max(maxFreq, it.second);
        minFreq = min(minFreq, it.second);
    }

    return maxFreq + minFreq;
}

int main()
{

    vector<int> arr = {1, 2, 2, 3, 3, 3};

    cout << "The sum of the frequencies of the highest occurring number and lowest occurring number is: " << sumHighestAndLowestFreq(arr);

    return 0;
}