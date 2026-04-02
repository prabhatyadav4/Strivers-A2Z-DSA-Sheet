// Recursive Approach for Forward Traversal

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int value) {
            this->data = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

void forwardTraversalRecursive(Node *head) {
    if(head == nullptr) return;

    cout << head->data;

    if(head->next != nullptr) {
        cout << " <-> ";
    }

    forwardTraversalRecursive(head->next);
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Forward Traversal (Recursive) : ";

    forwardTraversalRecursive(head);

    return 0;
}