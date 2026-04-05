/*
Delete head of Doubly Linked List

Given the head of a doubly linked list, remove the node at the head of the linked list and return the head of the modified list.

The head is the first node of the linked list.

Example 1

Input: doublyLinkedList = [1, 2, 3]

Output: [2, 3]

Explanation:

The node with value 1 was removed.
Example 2

Input: doublyLinkedList = [7]

Output: [ ]

Explanation:

Note that the head has null value after the removal.
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
     ListNode *deleteHead(ListNode *&head) {
        // Your code goes here
        if(head == nullptr) {
            return nullptr;
        }

        if(head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode *temp = head;
        head = head->next;
        head->prev = temp->prev;

        delete temp;
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

    head = obj.deleteHead(head);

    obj.printList(head);

    return 0;
}