# Singly Linked List

A singly linked list is a fundamental data structure, it consists of nodes where each node contains a data field and a reference to the next node in the linked list. 

The next of the last node is null, indicating the end of the list. Linked Lists support efficient insertion and deletion operations.

![Singly Linked List](https://media.geeksforgeeks.org/wp-content/uploads/20250901170546665785/link1.webp)

## Node Structure

```cpp
class Node {
    public: 
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
}; 
```

## Common Operations in Linked List

- **Traversal** : Traversing singly linked list
- **Insertion** : At the beginning, At the end and At a specific position
- **Deletion** : From beginning, From end and From a specific position
- **Searching** : Find whether a given key exists in the list
- **Updating** (Modification) : Modify contents of linked list.
- **Reversal** : Reverse the linked list and make the last node as new head.

## Applications of SinglyLinked List

- **Dynamic Memory Allocation** – Efficient use of memory with runtime size changes  
- **Stack & Queue Implementation** – Fast insertion/deletion (O(1))  
- **Sparse Matrices** – Stores only non-zero elements  
- **Polynomial Representation** – Easy mathematical operations  
- **Graph (Adjacency List)** – Space-efficient graph storage  
- **Hash Tables (Chaining)** – Handles collisions  
- **Memory Management** – Used in free lists by OS

## Advantage
- Dynamic size (no fixed limit like arrays)
- Efficient insertion and deletion at beginning and end. We also have insertion at the middle efficient if we have reference or pointer to the node after which we need to insert.
- Can implement complex data structures like stack, queue, graph

## Disadvantage
- Extra memory required for storing pointers
- No direct/random access (need traversal)
- Cache unfriendly (not stored in contiguous memory)