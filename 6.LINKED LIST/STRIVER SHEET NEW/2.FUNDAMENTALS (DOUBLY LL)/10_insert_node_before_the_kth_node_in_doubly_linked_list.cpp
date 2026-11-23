// Problem: Insert a new node before the Kth node.
// Positions are 1-based.

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

Node *insertBeforeKth(Node *head, int value, int k)
{
    if (head == nullptr || k <= 0)
    {
        return head;
    }

    Node *temp = head;

    for (int i = 1; i < k; i++)
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
    Node *prevNode = temp->prev;

    newNode->next = temp;
    newNode->prev = prevNode;

    if (prevNode != nullptr)
    {
        prevNode->next = newNode;
    }
    else
    {
        head = newNode;
    }

    temp->prev = newNode;

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

    head = insertBeforeKth(head, 3, 3);

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