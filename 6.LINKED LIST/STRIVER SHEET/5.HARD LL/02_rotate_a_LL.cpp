/*
61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

#include <iostream>
using namespace std;

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

// Brute force rotation by moving the last node to the front k times.
Node *BruteRotateList(Node *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }

    for (int i = 0; i < k; i++)
    {
        Node *curr = head;
        Node *prev = nullptr;

        // Find the last node and its previous node.
        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }

        // Detach the last node and move it to the front.
        prev->next = nullptr;
        curr->next = head;
        head = curr;
    }

    return head;
}

// Find and return the k-th node in the list (1-indexed).
Node *findKthNode(Node *temp, int k)
{
    int cnt = 1;
    while (temp)
    {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }
    return nullptr;
}

// Optimal rotation using list length and link rearrangement.
Node *OptimalRotateList(Node *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }

    Node *tail = head;
    int len = 1;

    // Compute the length and locate the last node.
    while (tail->next)
    {
        len++;
        tail = tail->next;
    }

    // Reduce k to within the list length.
    k = k % len;
    if (k == 0)
        return head;

    // Make the list circular temporarily.
    tail->next = head;

    // The new tail is at position len-k, and new head is its next node.
    Node *newLastNode = findKthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = nullptr;

    return head;
}

// Print the linked list contents.
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original Linked List: ";
    printList(head);

    cout << "BRUTE: Rotated Linked List: ";
    head = BruteRotateList(head, k);
    printList(head);

    cout << "OPTIMAL: Rotated Linked List: ";
    head = OptimalRotateList(head, k);
    printList(head);

    return 0;
}