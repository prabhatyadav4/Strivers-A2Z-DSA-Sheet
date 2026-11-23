// Problem: Create a doubly linked list containing nodes with data, prev and next pointers.

// Time Complexity: O(n) to create n nodes
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node *createDLL(int arr[], int n)
{
    if (n == 0)
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);

        temp->next = newNode;
        newNode->prev = temp;

        temp = newNode;
    }

    return head;
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    Node *head = createDLL(arr, n);

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
        {
            cout << "<->";
        }

        temp = temp->next;
    }

    return 0;
}