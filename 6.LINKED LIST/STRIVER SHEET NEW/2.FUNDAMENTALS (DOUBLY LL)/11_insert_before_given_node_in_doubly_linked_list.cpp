// Problem: Insert a new node immediately before a given node in a doubly linked list.

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

void insertBeforeNode(Node *node, int value)
{
    if (node == nullptr)
    {
        return;
    }

    Node *newNode = new Node(value);
    Node *prevNode = node->prev;

    newNode->next = node;
    newNode->prev = prevNode;

    if (prevNode != nullptr)
    {
        prevNode->next = newNode;
    }

    node->prev = newNode;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(4);

    head->prev = nullptr;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = nullptr;

    insertBeforeNode(third, 3);

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