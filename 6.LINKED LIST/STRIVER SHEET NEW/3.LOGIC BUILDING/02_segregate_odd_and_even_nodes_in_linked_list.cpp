/*
328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]


Constraints:
The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
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

Node *oddEvenList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = oddEvenList(head);

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