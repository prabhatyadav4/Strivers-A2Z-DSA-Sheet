/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false


Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
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

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = reverseLL(slow->next);

    Node *first = head;
    Node *second = secondHalf;

    bool result = true;

    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            result = false;
            break;
        }

        first = first->next;
        second = second->next;
    }

    slow->next = reverseLL(secondHalf);

    return result;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}