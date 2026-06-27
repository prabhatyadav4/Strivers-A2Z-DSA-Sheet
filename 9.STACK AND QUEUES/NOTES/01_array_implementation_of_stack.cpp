/*
Stack using Array

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle.
It can be implemented using an array by treating the end of the array as the top of the stack.

A stack can be implemented using an array where we maintain:
    An integer array to store elements.
    A variable capacity to represent the maximum size of the stack.
    A variable top to track the index of the top element. Initially, top = -1 to indicate an empty stack.
*/

#include <iostream>
using namespace std;

class Stack
{

    int *arr;
    int capacity;
    int top;

public:
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    // Push Operation
    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // Pop Operation
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Top Operation
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }
};

int main()
{
    Stack st(4);

    // Pushing Elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // Popping one element
    cout << "Popped: " << st.pop() << endl;

    // Checking top element
    cout << "Top element: " << st.peek() << endl;

    // Checking if stack is empty
    cout << "Is stack empty: " << st.isEmpty() << endl;

    // Checking if stack is full
    cout << "Is stack full: " << st.isFull() << endl;

    return 0;
}