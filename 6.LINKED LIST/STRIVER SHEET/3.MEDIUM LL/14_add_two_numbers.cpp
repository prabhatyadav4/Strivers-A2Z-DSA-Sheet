/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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

// Function to add two numbers represented as linked lists
// Lists are in reverse order, so LSB is at the head
Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Dummy node to simplify list creation
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    int carry = 0;

    // Traverse both lists and handle carry
    while (l1 != nullptr || l2 != nullptr || carry)
    {
        int sum = 0;

        // Add current node value from l1
        if (l1 != nullptr)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        // Add current node value from l2
        if (l2 != nullptr)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        // Add carry from previous iteration
        sum += carry;
        // Calculate new carry
        carry = sum / 10;
        // Create new node with digit (sum % 10)
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    // Return result list (skip dummy node)
    return dummy->next;
}

// Helper function to print linked list
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
    // Create first list: 1 -> 4 -> 3 (represents 341)
    Node *l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    // Create second list: 2 -> 0 -> 0 -> 5 (represents 5002)
    Node *l2 = new Node(2);
    l2->next = new Node(0);
    l2->next->next = new Node(0);
    l2->next->next->next = new Node(5);

    cout << "L1: ";
    printList(l1);
    cout << "L2: ";
    printList(l2);

    cout << "The sum of L1 and L2 is: ";
    Node *result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}