/*
295. Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

    MedianFinder() initializes the MedianFinder object.
    void addNum(int num) adds the integer num from the data stream to the data structure.
    double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]

Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0


Constraints:
-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.


Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class BruteMedianFinder
{
private:
    vector<int> nums;

public:
    BruteMedianFinder()
    {
    }

    void addNum(int num)
    {
        nums.push_back(num);
    }

    double findMedian()
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        if (n % 2 == 1)
        {
            return nums[n / 2];
        }

        return ((double)nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};

class OptimalMedianFinder
{
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
    OptimalMedianFinder()
    {
    }

    void addNum(int num)
    {
        leftMaxHeap.push(num);

        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        if (rightMinHeap.size() > leftMaxHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian()
    {
        if (leftMaxHeap.size() > rightMinHeap.size())
        {
            return leftMaxHeap.top();
        }

        return ((double)leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

int main()
{
    vector<int> nums = {5, 15, 1, 3, 2, 8};

    BruteMedianFinder brute;
    OptimalMedianFinder optimal;

    for (int num : nums)
    {
        brute.addNum(num);
        optimal.addNum(num);

        cout << "After adding " << num << ":\n";
        cout << "Brute median = " << brute.findMedian() << "\n";
        cout << "Optimal median = " << optimal.findMedian() << "\n\n";
    }

    return 0;
}