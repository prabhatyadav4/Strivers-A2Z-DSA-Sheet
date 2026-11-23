// Problem: Insert a new node immediately before the tail.

// Time Complexity: O(n)
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

Node *insertBeforeTail(Node *head, int value)
{
    if (head == nullptr)
    {
        return new Node(value);
    }

    if (head->next == nullptr)
    {
        Node *newNode = new Node(value);

        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }

        return newNode;
    }

    Node *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *newNode = new Node(value);
    Node *prevNode = tail->prev;

    newNode->next = tail;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    tail->prev = newNode;

    return head;
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

    head = insertBeforeTail(head, 3);

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