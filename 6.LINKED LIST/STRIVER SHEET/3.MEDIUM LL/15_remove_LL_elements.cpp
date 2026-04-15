/*
203. Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.



Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []


Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
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

// Approach 1: Remove elements by tracking previous node
Node *removeElements(Node *head, int val)
{
    // Base case: empty list
    if (head == nullptr)
        return head;

    Node *temp = head, *prev = nullptr;

    // Traverse the entire list
    while (temp != nullptr)
    {
        // If current node matches the value to remove
        if (temp->data == val)
        {
            // If it's the head node, move head pointer
            if (temp == head)
            {
                head = head->next;
            }
            // Otherwise, bypass the current node
            else
            {
                prev->next = temp->next;
            }

            // Delete the current node and move to next
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        // If current node doesn't match, move to next
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

// Approach 2: Optimal solution using dummy node
Node *OptimalRemoveElements(Node *head, int val)
{
    // Create dummy node to handle edge case of removing head
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *temp = dummy;

    // Traverse list and remove matching nodes
    while (temp->next != nullptr)
    {
        // If next node matches value, remove it
        if (temp->next->data == val)
        {
            Node *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
        // Otherwise, move to next node
        else
        {
            temp = temp->next;
        }
    }

    // Extract actual head and clean up dummy node
    Node *ans = dummy->next;
    delete dummy;

    return ans;
}

// Helper function to print the linked list
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

// Main function with test cases
int main()
{
    // Create sample linked list: 1->2->3->1->2->3->3->4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next = new Node(4);

    int val1 = 1;
    int val2 = 3;

    cout << "Original Linked List: ";
    printList(head);

    cout << "LL after deleting all 1's: ";
    head = removeElements(head, val1);
    printList(head);

    cout << "LL after deleting all 3's: ";
    head = removeElements(head, val2);
    printList(head);

    return 0;
}