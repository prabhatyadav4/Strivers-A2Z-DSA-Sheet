// Problem: Insert a node containing a given value at a specified 1-based position.

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

Node *insertNode(Node *head, int value, int k)
{
    if (k <= 0)
    {
        return head;
    }

    if (k == 1)
    {
        Node *newNode = new Node(value);
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }

        return newNode;
    }

    Node *temp = head;

    for (int i = 1; i < k - 1; i++)
    {
        if (temp == nullptr)
        {
            return head;
        }

        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return head;
    }

    Node *newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;

    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(4);

    head->next = second;
    head->prev = nullptr;

    second->next = third;
    second->prev = head;

    third->next = nullptr;
    third->prev = second;

    head = insertNode(head, 3, 3);

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