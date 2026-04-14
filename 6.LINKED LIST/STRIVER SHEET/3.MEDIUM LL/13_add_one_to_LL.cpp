/*
Add one to a number represented by LL

Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on.
The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

The number will contain no leading zeroes except when the value represented is zero itself.


Example 1

Input: head -> 1 -> 2 -> 3

Output: head -> 1 -> 2 -> 4

Explanation: The number represented by the linked list = 123.
123 + 1 = 124.

Example 2

Input: head -> 9 -> 9

Output: head -> 1 -> 0 -> 0

Explanation: The number represented by the linked list = 99.
99 + 1 = 100.

Constraints

0 <= number of nodes in the Linked List <= 105
0 <= ListNode.val <= 9
No leading zeroes in the value represented.
*/

#include <iostream>
using namespace std;

// Node structure for linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

// Helper function to reverse a linked list
Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *curr = head, *prev = nullptr, *front = nullptr;

    // Reverse by updating pointers
    while (curr != nullptr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

// Optimal approach: Reverse -> Add -> Reverse back
Node *OptimalAddOne(Node *head)
{
    if (head == nullptr)
    {
        return new Node(1);
    }

    // Reverse the list to access rightmost digit first
    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;

    // Add 1 starting from the rightmost digit
    while (temp != nullptr && carry)
    {
        temp->data += carry;
        carry = temp->data / 10;
        temp->data %= 10;
        temp = temp->next;
    }

    // Reverse back to original order
    head = reverseLL(head);

    // If carry remains, create new node at head
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Recursive helper function to add 1
int addOne(Node *temp)
{
    if (!temp)
        return 1;

    // Recursively go to the end
    int carry = addOne(temp->next);
    temp->data += carry;
    
    // If no carry, return 0
    if (temp->data < 10)
        return 0;
    
    // If overflow, set to 0 and return carry
    temp->data = 0;
    return 1;
}

// Recursive approach: Use recursion to reach the last node
Node *RecursiveAddOne(Node *head)
{
    if (head == nullptr)
    {
        return new Node(1);
    }

    int carry = addOne(head);
    
    // If carry remains after traversal, create new node
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create test list: 9 -> 9 -> 9
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    cout << "OPTIMAL: Modified Linked List: ";
    head = OptimalAddOne(head);
    printList(head);

    cout << "RECURSIVE: Modified Linked List: ";
    head = RecursiveAddOne(head);
    printList(head);

    return 0;
}