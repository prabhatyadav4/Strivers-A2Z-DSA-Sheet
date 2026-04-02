// Recursive Approach for Backward Traversal

#include <iostream>
using namespace std;

class Node {
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

void backwardTraversalRecursive(Node *tail) {
    if(tail == nullptr) return;

    cout << tail->data;

    if(tail->prev != nullptr) {
        cout << " <-> ";
    }

    backwardTraversalRecursive(tail->prev);
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Backward Traversal (Recursive): ";

    backwardTraversalRecursive(third);

    return 0;
}