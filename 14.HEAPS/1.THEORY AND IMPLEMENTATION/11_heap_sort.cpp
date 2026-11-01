/*
Given an array of integers nums, sort the array in non-decreasing order using the heap sort algorithm. Sort the given array itself, there is no need to return anything.

A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.

Example 1:
Input: nums = [7, 4, 1, 5, 3]

Output: [1, 3, 4, 5, 7]

Explanation:1 <= 3 <= 4 <= 5 <= 7.

One possible way to get the sorted array using heapSort :

[7, 4, 1, 5, 3] -> [3, 4, 1, 5, 7]

-> [5, 4, 1, 3, 7] -> [3, 4, 1, 5, 7]

-> [4, 3, 1, 5, 7] -> [1, 3, 4, 5, 7]

-> [3, 1, 4, 5, 7] -> [1, 3, 4, 5, 7]

-> [1, 3, 4, 5, 7] -> [1, 3, 4, 5, 7]

Example 2:
Input: nums = [5, 4, 4, 1, 1]

Output: [1, 1, 4, 4, 5]

Explanation: 1 <= 1 <= 4 <= 4 <= 5.

Thus the array is sorted in non-decreasing order.

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
nums[i] may contain duplicate values.
*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &nums, int n, int ind)
{
    int largest = ind;

    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if (left < n && nums[left] > nums[largest])
    {
        largest = left;
    }

    if (right < n && nums[right] > nums[largest])
    {
        largest = right;
    }

    if (ind != largest)
    {
        swap(nums[ind], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int> &nums)
{
    int n = nums.size();

    // PHASE 1: Build Max Heap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }

    // PHASE 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

void printArray(const vector<int> &nums)
{
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {7, 4, 1, 5, 3};

    cout << "Before sorting: ";
    printArray(nums);

    heapSort(nums);

    cout << "After sorting: ";
    printArray(nums);

    return 0;
}