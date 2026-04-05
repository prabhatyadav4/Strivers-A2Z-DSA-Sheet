/*
Insert node before head in Doubly Linked List

Given the head of a doubly linked list and an integer X, insert a node with value X before the head of the linked list and return the head of the modified list.

Example 1

Input: head = [1, 2, 3], X = 3

Output: head = [3, 1, 2, 3]

Explanation: 3 was added before the 1st node. Note that the head's value is changed.

Example 2

Input: head = [5], X = 7

Output: head = [7, 5]
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

class Solution
{
public:
    ListNode *insertBeforeHead(ListNode *head, int X)
    {
        // Your code goes here
        ListNode *newNode = new ListNode(X);

        ListNode *temp = head;

        newNode->next = temp;

        if (temp != nullptr)
        {
            temp->prev = newNode;
        }

        head = newNode;

        return head;
    }

    void printList(ListNode *head)
    {
        ListNode *curr = head;

        while (curr != nullptr)
        {
            cout << curr->data;
            if (curr->next != nullptr)
            {
                cout << " <-> ";
            }
            curr = curr->next;
        }

        cout << endl;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->prev = head;
    head->next->next = new ListNode(4);
    head->next->next->prev = head->next;

    int val = 1;

    head = obj.insertBeforeHead(head, val);

    obj.printList(head);

    return 0;
}