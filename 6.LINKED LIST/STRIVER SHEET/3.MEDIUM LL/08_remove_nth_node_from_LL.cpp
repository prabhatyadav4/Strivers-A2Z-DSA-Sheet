/*

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

Node *BruteRemoveNthFromEnd(Node *head, int n)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    int count = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    if (count == n)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int res = count - n;
    temp = head;

    while (res > 1)
    {
        temp = temp->next;
        res--;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

Node *OptimalRemoveNthFromEnd(Node *head, int n)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == nullptr)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;

    head = BruteRemoveNthFromEnd(head, n);
    cout << "BRUTE: The new linked list is: ";
    printList(head);

    head = OptimalRemoveNthFromEnd(head, n);
    cout << "Optimal: The new linked list is: ";
    printList(head);

    return 0;
}