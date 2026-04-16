/*
Remove duplicates from sorted DLL

Given the head of a doubly linked list with its values sorted in non-decreasing order.
Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

Return the head of the modified linked list.
*/

#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Function to remove duplicate values from sorted DLL
Node *removeDuplicates(Node *head)
{
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head;

    // Traverse through the list
    while (temp && temp->next)
    {
        Node *nextNode = temp->next;
        
        // Skip all nodes with same data as current node
        while (nextNode && temp->data == nextNode->data)
        {
            Node *delNode = nextNode;
            nextNode = nextNode->next;
            delete delNode;  // Free memory of duplicate node
        }

        // Link current node to next distinct node
        temp->next = nextNode;
        
        // Update previous pointer of next node
        if (nextNode)
            nextNode->prev = temp;
        
        // Move to next node
        temp = temp->next;
    }

    return head;
}

// Utility function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    cout << "[";
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

// Main function to test the solution
int main()
{
    // Create a sorted DLL: 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original Linked List: ";
    printList(head);

    cout << "LL after removing duplicates: ";
    head = removeDuplicates(head);
    printList(head);

    return 0;
}
