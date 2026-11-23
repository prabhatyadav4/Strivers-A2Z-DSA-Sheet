// Problem: Delete the head node of a doubly linked list.

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

Node *deleteHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    delete temp;

    return head;
}

int main()
{
    Node *head = new Node(0);
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->prev = nullptr;
    head->next = first;

    first->prev = head;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = nullptr;

    head = deleteHead(head);

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