// Insert Node at the End of a Linked List

#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;

        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

Node* insertAtEnd(Node* head, int x) {
    Node* newNode = new Node(x);

    if(head == nullptr) return newNode;

    Node* last = head;
    
    while(last->next != nullptr) {
        last = last->next;
    }

    last->next = newNode;

    return head;
}

void printList(Node* head) {
    Node* curr = head;

    while(curr != nullptr) {
        cout << curr->data;
        if(curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = insertAtEnd(head, 6);

    printList(head);

    return 0;
}