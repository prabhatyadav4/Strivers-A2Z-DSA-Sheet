/*
960. Build heap from a given Array

Given an array of integers nums, convert it in-place into a min-heap and max-heap.

A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

A Max Heap is a complete binary tree where each parent node is greater than or equal to its children, ensuring the largest element is at the root.

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int> &nums, int n, int ind)
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

    if (smallest != ind)
    {
        swap(nums[smallest], nums[ind]);
        minHeapify(nums, n, smallest);
    }
}

void maxHeapify(vector<int> &nums, int n, int ind)
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

    if (largest != ind)
    {
        swap(nums[largest], nums[ind]);
        maxHeapify(nums, n, largest);
    }
}

void buildMinHeap(vector<int> &nums)
{
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(nums, n, i);
    }
}

void buildMaxHeap(vector<int> &nums)
{
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(nums, n, i);
    }
}

int main()
{
    vector<int> nums = {10, 20, 15, 30, 40, 5, 8};

    vector<int> minHeap = nums;
    vector<int> maxHeap = nums;

    buildMinHeap(minHeap);
    buildMaxHeap(maxHeap);

    cout << "Min Heap: ";

    for (int x : minHeap)
    {
        cout << x << " ";
    }

    cout << "\nMax Heap: ";

    for (int x : maxHeap)
    {
        cout << x << " ";
    }

    return 0;
}

// STL Approach – Using Priority Queue

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {10, 20, 15, 30, 40, 5, 8};

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Max Heap
    priority_queue<int> maxHeap;

    for (int x : arr)
    {

        minHeap.push(x);
        maxHeap.push(x);
    }

    cout << "Min Heap: ";

    while (!minHeap.empty())
    {

        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << "\nMax Heap: ";

    while (!maxHeap.empty())
    {

        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}
*/