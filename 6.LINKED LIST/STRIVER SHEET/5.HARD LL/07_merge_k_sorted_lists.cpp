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
using namespace std;

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

// Brute-force merge k sorted linked lists by collecting all values and sorting them
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
    Node *mergedHead = BruteMergeKLists(listArray);

    cout << "\nMerged List:\n";
    printList(mergedHead);
    cout << endl;

    return 0;
}