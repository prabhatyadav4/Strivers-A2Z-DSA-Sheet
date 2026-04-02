# Doubly Linked List

A doubly linked list is a more complex data structure than a singly linked list, but it offers several advantages. The main advantage of a doubly linked list is that it allows for efficient traversal of the list in both directions. This is because each node in the list contains a pointer to the previous node and a pointer to the next node. This allows for quick and easy insertion and deletion of nodes from the list, as well as efficient traversal of the list in both directions.

![DLL1](https://media.geeksforgeeks.org/wp-content/uploads/20250827100441798494/11.webp)

## Representation of Doubly Linked List in Data Structure

In a data structure, a doubly linked list is represented using nodes that have three fields:

- Data
- A pointer to the next node (next)
- A pointer to the previous node (prev)

![DLL2](https://media.geeksforgeeks.org/wp-content/uploads/20250827100603409157/22.webp)

## Node Definition

Here is how a node in a Doubly Linked List is typically represented:

```Cpp

#include <iostream>
using namespace std;

class Node {
public:
    // To store the Value or data
    int data;

    // Pointer to point the Previous Element
    Node* prev;

    // Pointer to point the Next Element
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};
 ```

Each node in a Doubly Linked List contains the data it holds, a pointer to the next node in the list, and a pointer to the previous node in the list. By linking these nodes together through the next and prev pointers, we can traverse the list in both directions (forward and backward), which is a key feature of a Doubly Linked List.

## Creating a Doubly Linked List with 4 Nodes

- Create the head node.
    
    - Allocate a node and set head to it. Its prev and next should be null/None.
- Create the next node and link it to head.

    - head.next = new Node(value2)
    - head.next.prev = head
- Create further nodes the same way.

    - For the third node:

        => head.next.next = new Node(value3)

        => head.next.next.prev = head.next
    - Repeat until you have the required nodes.

Ensure the tail's next is null.

The last node you created must have next == null

Set / keep track of head (and optionally tail).

Use head to access the list from the front. Keeping a tail pointer simplifies appends.

## Common Operation in Doubly Linked List

**Traversal** : Display Linked List Elements
**Insertion** : At the Beginning, At the End and At the specific position
**Deletion** : From the Beginning, From End and From a Specific Position

## Applications of Doubly Linked List

- **Navigation Systems** – Used in browser history (back/forward)  
- **Undo/Redo Operations** – Editors like text editors  
- **Music/Video Playlist** – Move next and previous easily  
- **Deque Implementation** – Insert/delete from both ends efficiently  
- **LRU Cache** – Used with hash maps for fast access and deletion  

---

## Advantages of Doubly Linked List

- **Bidirectional Traversal** – Traverse forward (`next`) and backward (`prev`)  
- **Efficient Deletion** – O(1) deletion if node is known (no traversal needed)  
- **Insertion at Both Ends** – Easy insertion at head and tail  
- **Better Navigation** – Useful for undo/redo and backtracking features  

---

## Disadvantages of Doubly Linked List

- **Extra Memory Usage** – Additional `prev` pointer in each node  
- **Complex Implementation** – Need to manage both `next` and `prev` carefully  
- **Higher Overhead** – More pointer updates during insertion/deletion  
- **Not Cache-Friendly** – Non-contiguous memory reduces performance  