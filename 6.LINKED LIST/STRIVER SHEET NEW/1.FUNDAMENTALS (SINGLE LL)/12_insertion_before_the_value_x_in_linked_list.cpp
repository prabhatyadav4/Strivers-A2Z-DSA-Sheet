// Problem: Insert a new node before the first node containing value X.

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

Node *insertBeforeX(Node *head, int value, int X)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == X)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->next->data == X)
        {
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;

            return head;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);

    head = insertBeforeX(head, 4, 5);

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