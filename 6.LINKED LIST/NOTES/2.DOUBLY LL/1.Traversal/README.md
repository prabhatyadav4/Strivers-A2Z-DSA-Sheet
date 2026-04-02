# Traversal in Doubly Linked List

Traversal of Doubly Linked List is one of the fundamental operations, where we traverse or visit each node of the linked list. In this article, we will cover how to traverse all the nodes of a doubly linked list and its implementation.

Example:

Input: 10 <-> 20 <-> 30 <-> 40

Output: [10, 20, 30, 40] and [40, 30, 20, 10]

Explanation:
- Forward traversal moves from the first node to the last: [10, 20, 30, 40].
- Backward traversal moves from the last node to the first: [40, 30, 20, 10].

## Types of Traversal in Doubly Linked List

Since each node of Doubly Linked List has pointer to the next node as well as the previous node, we can traverse the linked list in two directions:

- Forward Traversal
- Backward Traversal

## Forward Traversal of Doubly Linked List

In Forward Traversal, we start from the first node, that is the head of the Doubly Linked List and continue visiting the next nodes using the next pointer of each node till we reach the last node of the linked list.

### 1. Iterative Approach for Forward Traversal

Follow the below steps:

- Initialize a pointer to the head of the linked list.
- While the pointer is not null:
  - Visit the data at the current node.
  - Move the pointer to the next node.

**Time Complexity**: O(n), where n is the number of nodes in the linked list
**Auxiliary Space**: O(1)

### 2. Recursive Approach for Forward Traversal

Follow the below steps:

- Maintain a recursive function, say forwardTraversal(head) which takes the pointer to a node as parameter.
- Inside forwardTraversal(head)
  - If the head pointer is NULL, then simply return from the function.
  - Otherwise, print the data inside the node and call the recursive function with the next node, forwardTraversal(head->next).

**Time Complexity**: O(n), where n is the number of nodes in the linked list
**Auxiliary Space**: O(n)

## Backward Traversal of Doubly Linked List

In Backward Traversal, we start from the last node, that is the tail of the Doubly Linked List and continue visiting the previous nodes using the prev pointer of each node till we reach the first node of the linked list.

### 1. Iterative Approach for Backward Traversal

Follow the below steps:

- Initialize a pointer to the tail of the linked list.
- While the pointer is not null:
  - Visit the data at the current node.
  - Move the pointer to the previous node.

**Time Complexity**: O(n), where n is the number of nodes in the linked list
**Auxiliary Space**: O(1)

### 2. Recursive Approach for Backward Traversal

Follow the below steps:

- Maintain a recursive function, say backwardTraversal(node) which takes the pointer to a node as parameter.
- Inside backwardTraversal(node)
  - If the head pointer is NULL, then simply return from the function.
  - Otherwise, print the data inside the node and call the recursive function with the previous node, backwardTraversal(node->prev).

**Time Complexity**: O(n), where n is the number of nodes in the linked list
**Auxiliary Space**: O(n)