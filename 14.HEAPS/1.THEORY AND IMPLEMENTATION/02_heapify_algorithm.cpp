/*
1021. Heapify Algorithm

Given an array nums representing a min-heap and two integers ind and val, set the value at index ind (0-based) to val and perform the heapify algorithm such that the resulting array follows the min-heap property.

Modify the original array in-place, no need to return anything.

Example 1:
Input: nums = [1, 4, 5, 5, 7, 6], ind = 5, val = 2

Output: [1, 4, 2, 5, 7, 5]

Explanation: After setting index 5 to 2, the resulting heap in array form = [1, 4, 5, 5, 7, 2]

Parent of nums[5] = nums[2] = 5 > nums[5] = 2, so they are swapped.

Final array = [1, 4, 2, 5, 7, 5]

Example 2:
Input: nums = [2, 4, 3, 6, 5, 7, 8, 7], ind = 0, val = 7

Output: [3, 4, 7, 6, 5, 7, 8, 7]

Explanation: After setting index 0 to 7, the resulting heap in array form =[7, 4, 3, 6, 5, 7, 8, 7]

The parent of nums[2] = nums[0] = 7 > nums[2] = 3, so they are swapped. No further swaps are needed.

Final array = [3, 4, 7, 6, 5, 7, 8, 7]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
0 <= ind < nums.length
-104 <= val <= 104
nums represents a min-heap
*/

#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(vector<int> &nums, int ind)
{
    while (ind > 0)
    {
        int parent = (ind - 1) / 2;

        if (nums[parent] > nums[ind])
        {
            swap(nums[parent], nums[ind]);
            ind = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(vector<int> &nums, int ind)
{
    int n = nums.size();

    while (true)
    {
        int smallest = ind;

        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && nums[left] < nums[smallest])
        {
            smallest = left;
        }

        if (right < n && nums[right] < nums[smallest])
        {
            smallest = right;
        }

        if (smallest == ind)
        {
            break;
        }

        swap(nums[ind], nums[smallest]);
        ind = smallest;
    }
}

void heapify(vector<int> &nums, int ind, int val)
{
    int oldVal = nums[ind];
    nums[ind] = val;

    if (val < oldVal)
    {
        heapifyUp(nums, ind);
    }
    else
    {
        heapifyDown(nums, ind);
    }
}

int main()
{
    vector<int> nums1 = {1, 4, 5, 5, 7, 6};
    int ind = 5, val = 2;

    vector<int> nums2 = {2, 4, 3, 5, 6, 7, 8, 7};
    int idx = 0, value = 7;

    heapify(nums1, ind, val);
    heapify(nums2, idx, value);

    cout << "Example 1: The required array is: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Example 2: The required array is: ";
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}