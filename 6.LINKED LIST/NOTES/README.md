# Linked List Data Structure

A linked list is a linear data structure where items are not necessarily at contiguous locations. Individual items called nodes are connected using links.

- Each node contains data and a link to the next node
- The first node is the head, used to traverse the entire list
- The last node points to null

![Linked List](https://media.geeksforgeeks.org/wp-content/uploads/20250619155958124670/Linked-list.webp)

## Types of Linked Lists

- Singly Linked List
- Doubly Linked List
- Circular Linked List

## Advantages

- **Efficient Insertion/Deletion**: O(1) time at known positions, unlike arrays which require shifting
- **Stack/Queue Implementation**: Simpler than circular arrays for implementing abstract data structures
- **Space Efficient**: Better than arrays when element count is unknown in advance
- **Dynamic Memory**: Avoids reallocation overhead of dynamic arrays

## Applications

- Implement stacks, queues, deques, and sparse matrices
- Operating systems: memory management, process scheduling, file systems
- LRU cache implementation
- Music players, web browsers, image viewers (navigation)
- Round-robin scheduling using circular linked lists

## Disadvantages

- **Slow Access**: O(n) traversal to find elements
- **Complexity**: Pointers/references are harder to understand than arrays
- **Memory Overhead**: Extra space needed for node links
- **Cache Inefficiency**: Non-contiguous memory causes cache misses

## Conclusion

Linked lists excel at frequent insertions/deletions but are slower for random access. Choose based on your use case requirements.