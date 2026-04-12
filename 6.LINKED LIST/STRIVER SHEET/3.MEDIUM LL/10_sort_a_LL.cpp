/*
148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
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

Node *BruteSortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    vector<int> arr;
    Node *temp = head;

    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;

    while (temp != nullptr)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

Node *mergeTwoSortedLL(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);

    Node *temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
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

    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    return dummyNode->next;
}

Node *findMiddle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *OptimalSortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *middle = findMiddle(head);

    Node *left = head;
    Node *right = middle->next;
    middle->next = nullptr;

    left = OptimalSortList(left);
    right = OptimalSortList(right);

    return mergeTwoSortedLL(left, right);
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);

    cout << "Original Linked List: ";
    printList(head);

    // cout << "BRUTE: Sorted Linked List: ";
    // head = BruteSortList(head);
    // printList(head);

    cout << "OPTIMAL: Sorted Linked List: ";
    head = OptimalSortList(head);
    printList(head);

    return 0;
}