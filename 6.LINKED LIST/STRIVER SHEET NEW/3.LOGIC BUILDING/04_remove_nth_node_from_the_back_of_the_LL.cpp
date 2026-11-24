/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]


Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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

Node *removeNthFromEnd(Node *head, int n)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < n; i++)
    {
        if (fast == nullptr)
        {
            return head;
        }

        fast = fast->next;
    }

    if (fast == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = removeNthFromEnd(head, 2);

    Node *temp = head;

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