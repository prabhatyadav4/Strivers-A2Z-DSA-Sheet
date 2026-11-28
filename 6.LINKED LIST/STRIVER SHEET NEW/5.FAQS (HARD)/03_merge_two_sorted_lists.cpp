/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]


Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

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

    Node *newHead = dummy->next;

    delete dummy;

    return newHead;
}

int main()
{
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    Node *result = mergeTwoLists(list1, list2);

    Node *temp = result;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
        {
            cout << "->";
        }

        temp = temp->next;
    }

    return 0;
}