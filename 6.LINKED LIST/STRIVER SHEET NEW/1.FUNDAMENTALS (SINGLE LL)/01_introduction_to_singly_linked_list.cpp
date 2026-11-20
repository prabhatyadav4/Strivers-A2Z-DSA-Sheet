// Problem: Create a singly linked list containing nodes with data and a pointer to the next node.

// Time Complexity: O(n) for creating n nodes
// Space Complexity: O(n)

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

// Solution function: Create a linked list from an array

Node *createLinkedList(const int arr[], int n)
{
    if (n == 0)
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    Node *head = createLinkedList(arr, n);

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