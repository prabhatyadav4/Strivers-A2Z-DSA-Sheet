/*
Deletion of the head of LL

Given the head of a singly linked list, delete the head of the linked list and return the head of the modified list. The head is the first node of the linked list.

Note : Please note that this section might seem a bit difficult without prior knowledge on what linkedList is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!

Example 1

Input: linkedList = [1, 2, 3]

Output: [2, 3]

Explanation:

The first node was removed.

Example 2

Input: linkedList = [1]

Output: []

Explanation:

Note that the head of the linked list gets changed.
*/

#include <iostream>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteHead(ListNode *&head)
    {
        // your code goes here
        ListNode *temp = head;
        head = temp->next;

        return head;
    }

    void printList(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->data;

            if (head->next != nullptr)
            {
                cout << " -> ";
            }

            head = head->next;
        }

        cout << endl;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    head = obj.deleteHead(head);

    obj.printList(head);

    return 0;
}