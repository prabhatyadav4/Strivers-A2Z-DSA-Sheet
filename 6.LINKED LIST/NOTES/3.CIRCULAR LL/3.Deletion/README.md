# Deletion from a Circular Linked List

In a circular linked list, the last node connects back to the first node, creating a loop.

There are three main ways to delete a node from circular linked list:

- Deletion at the beginning
- Deletion at specific position
- Deletion at the end

Now, let’s look at the methods and steps for these three deletion operations.

## Deletion from a Circular Linked List

Deletion involves removing a node from the linked list. The main difference is that we need to ensure the list remains circular after the deletion. We can delete a node in a circular linked list in three ways:

### 1. Deletion from the beginning of the circular linked list - O(1) Time and O(1) Space

To delete the first node of a circular linked list, check if the list is empty and return NULL if so. If it has only one node, delete it and set last = NULL. Otherwise, update last->next to skip the head, delete the head node, and return the updated last pointer.

**Step-by-step approach:**

- Check if List is Empty: If last is nullptr, print "List is empty" and return nullptr.
- Get Head Node: Set head to last->next.
- Check for Single Node: If head equals last, delete head and set last to nullptr.
- Handle Multiple Nodes:
=> Update last->next to point to head->next.
=> Delete head.
- Return Updated last

### 2. Deletion at specific position in circular linked list - O(n) Time and O(1) Space
To delete a specific node from a circular linked list, check if the list is empty. If it has only one node and matches the key, delete it and set the list to empty. Otherwise, traverse with two pointers to find the node. If found, adjust the links to remove it and return the updated list; if not found, leave the list unchanged.

**Step-by-step approach:**

- Check if the list is empty (last is None). If yes, return None.
- Set curr to last.next (head) and prev to last.
- If the list has only one node (curr == last) and the node’s data matches key, delete it by setting last = None and return.
- If the head node’s data matches key, update last.next to skip the head node and return last.
- Otherwise, traverse the list using curr and prev until you either reach back to last or find the node with key.
- If the node with key is found:
=> Update prev.next to skip curr
=> If curr is the last node, update last = prev.
- Return the updated last.

### 3. Deletion at the end of Circular linked list - O(n) Time and O(1) Space
To delete the last node in a circular linked list, first check if the list is empty. If it has only one node, delete it and set last to nullptr. Otherwise, traverse to the second last node, update its next to point to the head, delete the last node, and update last to the second last node.

**Step-by-step approach:**

- Check if the list is empty (last == None). If yes, return None.
- Set head = last.next.
- If the list has only one node (head == last), delete it by setting last = None and return.
- Traverse the list using a pointer curr starting from head until curr.next == last.
- Update curr.next = head to skip the last node.
- Delete the last node and update last = curr.
- Return the updated last.