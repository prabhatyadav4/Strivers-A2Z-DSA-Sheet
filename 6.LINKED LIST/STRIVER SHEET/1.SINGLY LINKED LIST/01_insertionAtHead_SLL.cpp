/*
Insertion at the head of Linked List

Given the head of a singly linked list and an integer X, insert a node with value X at the head of the linked list and return the head of the modified list.

Example 1

Input: linkedList = [1, 2, 3], X = 7

Output: [7, 1, 2, 3]

Explanation:

7 was added as the 1st node.

Example 2

Input: linkedList = [], X = 7

Output: [7]

Explanation:

7 was added as the 1st node.
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
    ListNode *insertAtHead(ListNode *&head, int X)
    {
        // your code goes here
        ListNode *newNode = new ListNode(X);
        newNode->next = head;
        head = newNode;

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

    head = obj.insertAtHead(head, 5);

    obj.printList(head);

    return 0;
}