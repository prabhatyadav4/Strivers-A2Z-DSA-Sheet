/*
Implement Stack using Array

Problem Statement: Implement a Last-In-First-Out (LIFO) stack using an array.
The implemented stack should support the following operations: push, pop, peek, and isEmpty.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the top element of the stack.
int top(): Returns the top element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.

Examples

Example 1:
Input:
["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
[[], [5], [10], [], [], []]

Output:
  [null, null, null, 10, 10, false]

Explanation:
ArrayStack stack = new ArrayStack();
- stack.push(5);
- stack.push(10);
- stack.top(); // returns 10
- stack.pop(); // returns 10
- stack.isEmpty(); // returns false

Example 2:
Input:
["ArrayStack", "isEmpty", "push", "pop", "isEmpty"]
[[], [], [1], [], []]

Output:
 [null, true, null, 1, true]

Explanation:
  ArrayStack stack = new ArrayStack();
- stack.push(1);
- stack.pop(); // returns 1
- stack.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

class ArrayStack
{
private:
    int *stackArray;
    int capacity;
    int topIndex;

public:
    ArrayStack(int size = 1000)
    {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack()
    {
        delete[] stackArray;
    }

    // Push element x

    void push(int x)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns the top element

    int pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }

    // Returns top element

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }

    // Returns true if stack is empty else false

    bool isEmpty()
    {
        return topIndex == -1;
    }
};

int main()
{
    ArrayStack st(4);

    // Pushing Elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // Popping one element
    cout << "Popped: " << st.pop() << endl;

    // Checking top element
    cout << "Top element: " << st.top() << endl;

    // Checking if stack is empty
    cout << "Is stack empty: " << st.isEmpty() << endl;

    return 0;
}