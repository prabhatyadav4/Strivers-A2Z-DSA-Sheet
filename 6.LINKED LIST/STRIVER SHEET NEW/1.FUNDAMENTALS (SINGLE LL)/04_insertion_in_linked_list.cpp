// Problem: Insert a new node containing a given value at a specified 1-based position.

// Time Complexity: O(n)
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

Node *insertNode(Node *head, int value, int position)
{
    if (position <= 0)
    {
        return head;
    }

    if (position == 1)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1; i++)
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
    temp->next = newNode;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);

    head = insertNode(head, 4, 4);

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