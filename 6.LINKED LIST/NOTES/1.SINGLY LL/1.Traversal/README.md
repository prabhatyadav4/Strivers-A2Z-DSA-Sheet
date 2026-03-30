# Traversal of Singly Linked List

Traversal of Singly Linked List is one of the fundamental operations, where we traverse or visit each node of the linked list.

Input: 

![Traversal](https://media.geeksforgeeks.org/wp-content/uploads/20250827185547966979/blobid0_1755936039.webp)

Output: 1 -> 2 -> 3 -> 4 -> 5 

Explanation: Every element of each node from head node to last node is printed which means we have traversed each node successfully.

## Traversal of Singly Linked List (Iterative Approach)

The process of traversing a singly linked list involves printing the value of each node and then going on to the next node and print that node's value also and so on, till we reach the last node in the singly linked list, whose next node points towards the null.

### Step-by-Step Algorithm:

- We will initialize a temporary pointer to the head node of the singly linked list.
- After that, we will check if that pointer is null or not null, if it is null, then return.
- While the pointer is not null, we will access and print the data of the current node, then we move the pointer to next node.

## Traversal of Singly Linked List (Recursive Approach)
We can also traverse the singly linked list using recursion. We start at the head node of the singly linked list, check if it is null or not and print its value. We then call the traversal function again with the next node passed as pointer.

### Step-by-Step Algorithm:

- Firstly, we define a recursive method to traverse the singly linked list, which takes a node as a parameter.
- In this function, the base case is that if the node is null then we will return from the recursive method.
- We then pass the head node as the parameter to this function.
- After that, we access and print the data of the current node.
- At last, we will make a recursive call to this function with the next node as the parameter.