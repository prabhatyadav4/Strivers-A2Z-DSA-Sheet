/*
Delete all occurrences of a key in DLL

Given the head of a doubly linked list and an integer target.
Delete all nodes in the linked list with the value target and return the head of the modified linked list.


Example 1

Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
Output: head -> 2 <-> 3 <-> 4
Explanation: All nodes with the value 1 were removed.

Example 2
Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2
Output: head -> 3 <-> -1 <-> 4
Explanation: All nodes with the value 2 were removed.
Note that the value of head is changed.

Constraints

0 <= number of nodes in the linked list <= 105
-104 <= ListNode.val <= 104
-104 <= target <= 104
*/

#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node
{
public:
    int data;
    Node *prev; // Pointer to previous node
    Node *next; // Pointer to next node

    // Constructor to initialize a new node
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Function to delete all occurrences of a value from DLL
Node *deleteAllOccurences(Node *head, int val)
{
    // Base case: empty list
    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    // Traverse the entire list
    while (temp != nullptr)
    {
        // Check if current node's data matches the target value
        if (temp->data == val)
        {
            // If the node to delete is head, update head pointer
            if (temp == head)
            {
                head = temp->next;
            }

            // Store pointers to previous and next nodes
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            // Reconnect the links to bypass the deleted node
            if (prevNode != nullptr)
                prevNode->next = nextNode;
            if (nextNode != nullptr)
                nextNode->prev = prevNode;

            // Free the memory of deleted node
            delete temp;
            // Move to next node
            temp = nextNode;
        }
        else
        {
            // If data doesn't match, move to next node
            temp = temp->next;
        }
    }

    return head;
}

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    // Traverse and print each node
    while (temp != nullptr)
    {
        cout << temp->data;
        // Print separator if not the last node
        if (temp->next != nullptr)
        {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 1 <-> 2
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(1);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->prev = head->next->next->next;

    int val = 1;

    cout << "Original Linked List: ";
    printList(head);

    // Delete all occurrences of target value
    cout << "DLL after deleting all 1's: ";
    head = deleteAllOccurences(head, val);
    printList(head);

    return 0;
}