// Problem: Insert a new node before the head of a doubly linked list.

// Time Complexity: O(1)
// Space Complexity: O(1) auxiliary space

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

Node *insertBeforeHead(Node *head, int value)
{
    Node *newNode = new Node(value);

    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;
    }

    return newNode;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->prev = nullptr;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = nullptr;

    head = insertBeforeHead(head, 0);

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