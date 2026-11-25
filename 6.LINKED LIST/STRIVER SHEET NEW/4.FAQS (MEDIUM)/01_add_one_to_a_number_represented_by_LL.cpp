/*
767. Add one to a number represented by LL

Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

The number will contain no leading zeroes except when the value represented is zero itself.

Example 1:
Input: head -> 1 -> 2 -> 3

Output: head -> 1 -> 2 -> 4

Explanation: The number represented by the linked list = 123.

123 + 1 = 124.

Example 2:
Input: head -> 9 -> 9

Output: head -> 1 -> 0 -> 0

Explanation: The number represented by the linked list = 99.

99 + 1 = 100.

Constraints:
0 <= number of nodes in the Linked List <= 105
0 <= ListNode.val <= 9
No leading zeroes in the value represented.
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

Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

Node *addOne(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    head = reverseLL(head);

    Node *temp = head;
    int carry = 1;

    while (temp != nullptr || carry)
    {
        int sum = temp->data + carry;

        temp->data = sum % 10;
        carry = sum / 10;

        if (carry && temp->next == nullptr)
        {
            temp->next = new Node(0);
        }

        temp = temp->next;
    }

    return reverseLL(head);
}

int main()
{
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    head = addOne(head);

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