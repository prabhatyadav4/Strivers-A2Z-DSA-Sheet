// Problem: Insert a new node at the beginning of a singly linked list.

// Time Complexity: O(1)
// Space Complexity: O(1) auxiliary space

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

Node *insertAtHead(Node *head, int value)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = insertAtHead(head, 0);

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