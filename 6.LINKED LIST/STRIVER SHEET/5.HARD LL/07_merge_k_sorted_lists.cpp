/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
    1->4->5,
    1->3->4,
    2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Node structure for singly linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

// Convert an array of integers into a singly linked list
// Time: O(n), Space: O(n)
Node *convertArrToLL(vector<int> &arr)
{
    Node *dummyNode = new Node(-1); // dummy head to simplify insertion
    Node *temp = dummyNode;

    for (int i = 0; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    Node *newHead = dummyNode->next; // actual head of the created list
    delete dummyNode;                // delete the temporary dummy node
    return newHead;
}

// BRUTE FORCE: Extract all values, sort them, and rebuild the list
// Time: O(N*logN) where N is total number of nodes, Space: O(N)
Node *BruteMergeKLists(vector<Node *> &listArray)
{
    vector<int> arr;

    // Extract all node values from each linked list
    for (int i = 0; i < listArray.size(); i++)
    {
        Node *temp = listArray[i];

        while (temp)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }

    sort(arr.begin(), arr.end()); // sort all values

    // Convert sorted values back into a new linked list
    return convertArrToLL(arr);
}

// Merge two sorted linked lists into one
// Time: O(m+n), Space: O(1)
Node *mergeTwoSortedLL(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    // Compare nodes from both lists and attach the smaller one
    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    // Attach remaining nodes from either list
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;

    Node *newHead = dummy->next;
    delete dummy;
    return newHead;
}

// BETTER APPROACH: Sequentially merge lists one by one
// Time: O(N*k) where N is total nodes and k is number of lists, Space: O(1)
Node *BetterMergeKLists(vector<Node *> &listArray)
{
    if(listArray.size() == 0) return nullptr;
    Node *head = listArray[0];

    // Merge each list with the previous result
    for (int i = 1; i < listArray.size(); i++)
    {
        head = mergeTwoSortedLL(head, listArray[i]);
    }

    return head;
}

// OPTIMAL APPROACH: Use min-heap (priority queue) to efficiently get smallest element
// Time: O(N*logk) where N is total nodes and k is number of lists, Space: O(k)
Node *OptimalMergeKLists(vector<Node *> &listArray)
{
    // Min-heap storing (node value, node pointer) pairs
    priority_queue<pair<int, Node *>,
                   vector<pair<int, Node *>>, greater<pair<int, Node *>>>
        pq;

    // Initialize heap with first node from each list
    for (int i = 0; i < listArray.size(); i++)
    {
        if (listArray[i] != nullptr)
        {
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    Node *dummy = new Node(-1);
    Node *tail = dummy;

    // Extract min element, append to result, and insert next element from same list
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        
        tail->next = it.second;
        tail = tail->next;

        // Add next node from the same list if it exists
        if (it.second->next)
        {
            pq.push({it.second->next->data, it.second->next});
        }

        tail->next = nullptr;
    }

    Node *newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Print the linked list contents
void printList(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating 3 sorted linked lists
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    Node *list1 = convertArrToLL(arr1);
    Node *list2 = convertArrToLL(arr2);
    Node *list3 = convertArrToLL(arr3);

    vector<Node *> listArray = {list1, list2, list3};

    cout << "Input Lists:\n";
    printList(list1);
    printList(list2);
    printList(list3);

    // Merge all lists into one sorted list
    Node *mergedHead1 = BruteMergeKLists(listArray);
    cout << "\nBRUTE: Merged List:\n";
    printList(mergedHead1);

    Node *mergedHead2 = BetterMergeKLists(listArray);
    cout << "\nBETTER: Merged List:\n";
    printList(mergedHead2);

    Node *mergedHead3 = OptimalMergeKLists(listArray);
    cout << "\nOPTIMAL: Merged List:\n";
    printList(mergedHead3);

    return 0;
}