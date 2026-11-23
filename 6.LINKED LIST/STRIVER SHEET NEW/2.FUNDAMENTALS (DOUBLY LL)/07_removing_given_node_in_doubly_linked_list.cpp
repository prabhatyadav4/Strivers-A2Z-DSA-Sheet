// Problem: Delete a given node from a doubly linked list.
// The given node is assumed not to be the tail.

// Time Complexity: O(1)
// Space Complexity: O(1)

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

void deleteGivenNode(Node *node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return;
    }

    Node *nextNode = node->next;

    node->data = nextNode->data;
    node->next = nextNode->next;

    if (nextNode->next != nullptr)
    {
        nextNode->next->prev = node;
    }

    delete nextNode;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(3);

    head->prev = nullptr;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = nullptr;

    deleteGivenNode(third);

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