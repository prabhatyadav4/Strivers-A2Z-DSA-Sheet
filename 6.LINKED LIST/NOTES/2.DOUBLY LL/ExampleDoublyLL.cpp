// Creating a Doubly Linked List with 4 Nodes

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

int main() {
    Node *head = new Node(1);

    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data;
        if(temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }

    return 0;
}