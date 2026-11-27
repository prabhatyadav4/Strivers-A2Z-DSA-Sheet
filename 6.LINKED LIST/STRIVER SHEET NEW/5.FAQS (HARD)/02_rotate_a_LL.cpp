/*
61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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

Node *rotateRight(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k <= 0)
    {
        return head;
    }

    int len = 1;
    Node *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
        len++;
    }

    k = k % len;

    if (k == 0)
    {
        tail->next = nullptr;
        return head;
    }

    tail->next = head;

    int steps = len - k;
    Node *newTail = head;

    for (int i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = rotateRight(head, 2);

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
        {
            cout << " ";
        }

        temp = temp->next;
    }

    return 0;
}