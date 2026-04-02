// Iterative Approach for Backward Traversal

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

void backwardTraversalIterative(Node *tail) {
    Node *curr = tail;

    while(curr != nullptr) {
        cout << curr->data;
        if(curr->prev != nullptr) {
            cout << " <-> ";
        }
        curr = curr->prev;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Backward Traversal (Iterative): ";
    
    backwardTraversalIterative(third);

    return 0;
}