/*
Stack - Linked List Implementation

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. 
It can be implemented using a linked list, where each element of the stack is represented as a node. 
The head of the linked list acts as the top of the stack.

Declaration of Stack using Linked List:

A stack can be implemented using a linked list where we maintain:
    A Node structure/class that contains:
        data → to store the element.
        next → pointer/reference to the next node in the stack.
    A pointer/reference top that always points to the current top node of the stack.
    Initially, top = null to represent an empty stack.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;
    int count;

public:
    Stack()
    {
        top = NULL;
        count = 0;
    }

    // Push operation
    void push(int x)
    {
        Node *temp = new Node(x);
        if (temp == NULL)
        {
            cout << "Stack overflow" << endl;
        }
        temp->next = top;
        top = temp;

        count++;
        cout << x << " pushed into the stack." << endl;
    }

    // Pop operation
    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node *temp = top;
        top = top->next;
        int val = temp->data;
        count--;
        delete temp;
        return val;
    }

    // Peek operation
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    // C    heck if stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Size of stack
    int size()
    {
        return count;
    }
};

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Popped: " << st.pop() << endl;
    cout << "Top Element: " << st.peek() << endl;
    cout << "Is stack empty: " << st.isEmpty() << endl;
    cout << "Size of stack: " << st.size() << endl;

    return 0;
}