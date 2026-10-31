/*
140. Implement Min Heap

You need to implement the Min Heap with the following given methods.

    insert (x) -> insert value x to the min heap
    getMin -> Output the minimum value from min heap
    exctractMin -> Remove the minimum element from the heap
    heapSize -> return the current size of the heap
    isEmpty -> returns if heap is empty or not
    changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)
    initializeHeap -> Initialize the heap

Example 1:
Input : operation = [ "initializeheap", "insert", "insert", "insert", "getMin", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" ]

nums = [ [4], [1], [10], [0, 16] ]

Output : [ null, null, null, null, 1, 3, 0, null, null, 10 ]

Explanation : In 1st operation we initialize the heap to empty heap.

In 2nd, 3rd, 4th operation we insert 4, 1, 10 to the heap respectively. The heap after 4th operation will be -> [1, 4, 10].

In 5th operation we output the minimum element from the heap i.e. 1.

In 6th operation we output the size of the current heap i.e. 3.

In 7th operation we output whether the heap is empty or not i.e. false (0).

In 8th operation we remove the minimum element from heap. So the ne heap becomes -> [4, 10].

In 9th operation we change the 0th index element to 16. So new heap becomes -> [16, 10]. After heapify -> [10, 16].

In 10th operation we output the minimum element of the heap i.e. 10.

Constraints:
1 <= n <= 105
-105 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

public:
    // Initialize an empty heap
    void initializeHeap()
    {
        heap.clear();
    }

    // Insert an element into Min Heap
    void insert(int x)
    {
        heap.push_back(x);

        int i = heap.size() - 1;

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i])
            {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    // Return minimum element
    int getMin()
    {
        if (heap.empty())
        {
            return -1;
        }

        return heap[0];
    }

    // Remove minimum element
    void extractMin()
    {
        if (heap.empty())
        {
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        int n = heap.size();

        while (true)
        {
            int smallest = i;

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] < heap[smallest])
            {
                smallest = left;
            }

            if (right < n && heap[right] < heap[smallest])
            {
                smallest = right;
            }

            if (smallest == i)
            {
                break;
            }

            swap(heap[i], heap[smallest]);

            i = smallest;
        }
    }

    // Return current heap size
    int heapSize()
    {
        return heap.size();
    }

    // Check whether heap is empty
    bool isEmpty()
    {
        return heap.empty();
    }

    // Update value at given index
    void changeKey(int ind, int val)
    {
        if (ind < 0 || ind >= heap.size())
        {
            return;
        }

        int oldVal = heap[ind];
        heap[ind] = val;

        if (val < oldVal)
        {

            // Heapify Up
            while (ind > 0)
            {
                int parent = (ind - 1) / 2;

                if (heap[parent] > heap[ind])
                {
                    swap(heap[ind], heap[parent]);
                    ind = parent;
                }
                else
                {
                    break;
                }
            }
        }
        else if (val > oldVal)
        {

            // Heapify Down
            int n = heap.size();

            while (true)
            {
                int smallest = ind;

                int left = 2 * ind + 1;
                int right = 2 * ind + 2;

                if (left < n && heap[left] < heap[smallest])
                {
                    smallest = left;
                }
                if (right < n && heap[right] < heap[smallest])
                {
                    smallest = right;
                }
                if (smallest == ind)
                {
                    break;
                }

                swap(heap[ind], heap[smallest]);
                ind = smallest;
            }
        }
    }
};

int main()
{
    MinHeap minHeap;

    // Start with an empty heap, then insert three values.
    minHeap.initializeHeap();
    minHeap.insert(4);
    minHeap.insert(1);
    minHeap.insert(10);

    cout << "Minimum after inserting 4, 1, and 10: " << minHeap.getMin() << '\n';
    cout << "Heap size: " << minHeap.heapSize() << '\n';
    cout << "Is the heap empty? " << (minHeap.isEmpty() ? "yes" : "no") << '\n';

    // Remove the minimum (1). The heap now contains 4 and 10.
    minHeap.extractMin();
    cout << "Minimum after extractMin: " << minHeap.getMin() << '\n';

    // Change the root (4) to 16. It moves down so the heap remains valid.
    minHeap.changeKey(0, 16);
    cout << "Minimum after changing index 0 to 16: " << minHeap.getMin() << '\n';
    cout << "Heap size after these operations: " << minHeap.heapSize() << '\n';

    // Remove the remaining elements to demonstrate the empty-heap check.
    minHeap.extractMin();
    minHeap.extractMin();
    cout << "Is the heap empty after removing all elements? "
         << (minHeap.isEmpty() ? "yes" : "no") << '\n';

    return 0;
}