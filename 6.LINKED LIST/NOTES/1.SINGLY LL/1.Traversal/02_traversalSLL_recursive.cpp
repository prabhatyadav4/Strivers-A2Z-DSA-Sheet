#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;

        Node(int new_data) {
            this->data = new_data;
            this->next = nullptr;
        }
};

void traverseList(Node* head) {
    if(head == nullptr) {
        cout << endl;
        return;
    }

    cout << head->data;

    if(head->next != nullptr) {
        cout << " -> ";
    }

    traverseList(head->next);
}

int main() {
    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverseList(head);

    return 0;
}