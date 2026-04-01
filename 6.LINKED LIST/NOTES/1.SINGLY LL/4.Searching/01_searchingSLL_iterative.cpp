// Search an element in a Linked List - Iterative Approach

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

bool searchKey(Node* head, int key) {
    Node* curr = head;

    while(curr != nullptr) {
        if(curr->data == key)   return true;
        curr = curr->next;
    }

    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int key = 3;

    searchKey(head, key) ? cout << "True" : cout << "False";

    return 0;
}