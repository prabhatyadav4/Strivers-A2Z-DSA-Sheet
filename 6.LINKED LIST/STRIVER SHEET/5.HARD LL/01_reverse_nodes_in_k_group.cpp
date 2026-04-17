/*
25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/

#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node
{
public:
    int data;      // Data stored in the node
    Node *next;    // Pointer to the next node

    // Constructor to initialize node with data
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

// Function to reverse a linked list iteratively
// Returns the new head of the reversed list
Node *reverseList(Node *head)
{
    // Base case: if list is empty or has one node, return as is
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *curr = head;  // Current node pointer
    Node *prev = nullptr;  // Previous node pointer

    // Traverse the list and reverse pointers
    while (curr != nullptr)
    {
        Node *front = curr->next;  // Store next node
        curr->next = prev;         // Reverse current node's pointer
        prev = curr;               // Move prev to current
        curr = front;              // Move to next node
    }

    return prev;  // New head of reversed list
}

// Function to find the k-th node from the given node
// Returns the k-th node or nullptr if not enough nodes
Node *findKthNode(Node *temp, int k)
{
    k--;  // Decrement k since we start from temp
    // Traverse k-1 steps
    while (temp && k > 0)
    {
        k--;
        temp = temp->next;
    }

    return temp;  // Return the k-th node
}

// Function to reverse nodes in k-groups
// Returns the head of the modified list
Node *reverseKGroup(Node *head, int k)
{
    // If list is empty, return nullptr
    if (head == nullptr)
        return nullptr;

    Node *temp = head;      // Temporary pointer to traverse the list
    Node *prevNode = nullptr;  // Pointer to the node before the current group

    // Loop until we can't find a full group of k nodes
    while (temp != nullptr)
    {
        // Find the k-th node from temp
        Node *kthNode = findKthNode(temp, k);
        // If not enough nodes, connect prevNode to temp and break
        if (kthNode == nullptr)
        {
            if (prevNode)
                prevNode->next = temp;
            break;
        }
        // Store the node after kthNode
        Node *nextNode = kthNode->next;
        // Disconnect the group by setting kthNode->next to nullptr
        kthNode->next = nullptr;
        // Reverse the current group
        reverseList(temp);
        // If this is the first group, update head
        if (head == temp)
        {
            head = kthNode;
        }
        else
        {
            // Connect previous group to the reversed current group
            prevNode->next = kthNode;
        }
        // Update prevNode to the start of the current group (now reversed)
        prevNode = temp;
        // Move temp to the next group
        temp = nextNode;
    }

    return head;  // Return the modified list head
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    // Traverse and print each node's data
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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;  // Group size for reversal

    cout << "Original Linked List: ";
    printList(head);

    cout << "Reverse LL in k group: ";
    // Reverse in k-groups and update head
    head = reverseKGroup(head, k);
    printList(head);

    return 0;
}