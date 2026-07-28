/*
Implement stack using Linkedlist

Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support the following operations: push, pop, top, and isEmpty.

Implement the LinkedListStack class:

void push(int x): Pushes element x onto the stack.

int pop(): Removes and returns the top element of the stack.

int top(): Returns the top element of the stack without removing it.

boolean isEmpty(): Returns true if the stack is empty, false otherwise.


Example 1

Input:

["LinkedListStack", "push", "push", "pop", "top", "isEmpty"]

[[], [3], [7], [], [], []]

Output: [null, null, null, 7, 3, false]

Explanation:

LinkedListStack stack = new LinkedListStack();

stack.push(3);

stack.push(7);

stack.pop(); // returns 7

stack.top(); // returns 3

stack.isEmpty(); // returns false

Example 2

Input:

["LinkedListStack", "isEmpty"]

[[]]


Output: [null, true]

Explanation:

LinkedListStack stack = new LinkedListStack();

stack.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    void push(int x)
    {
        Node *newNode = new Node(x);

        newNode->next = top;
        top = newNode;
        count++;

        cout << x << " pushed into the stack" << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }

        Node *temp = top;
        int value = temp->data;

        top = top->next;
        delete temp;
        count--;

        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

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

    cout << "Popped: " << st.pop() << '\n';
    cout << "Top Element: " << st.peek() << '\n';
    cout << boolalpha;
    cout << "Is stack empty: " << st.isEmpty() << '\n';
    cout << "Size of stack: " << st.size() << '\n';

    return 0;
}