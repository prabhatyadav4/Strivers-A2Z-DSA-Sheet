# Introduction to Heap


Imagine an emergency room with several waiting patients. The patient needing the most urgent care is treated first, even if another patient arrived earlier. The next choice depends on priority, not arrival time.

A Heap helps manage this kind of priority. A Heap keeps the smallest or largest value at the top, so the next important value can be found quickly. Heaps are commonly used to build priority queues, find top values, schedule tasks, and support graph algorithms.

This article focuses on the Binary Heap, the most common Heap used in Data Structures and Algorithms. The discussion covers Heapify, Build Heap, Min Heap, Max Heap, checking a Min Heap, and converting a Min Heap into a Max Heap. No code is needed to understand the main ideas.

## 1. What is a Heap?

A Heap is a tree-based data structure that follows a special order between every parent and its children. A Binary Heap also follows a strict shape: every level is filled before the next level begins.

A Heap does not keep every value in sorted order. A Heap only keeps enough order to make one extreme value easy to reach:

- A **Min Heap** keeps the smallest value at the root.
- A **Max Heap** keeps the largest value at the root.

The root is the top node of the tree. Reading the root takes constant time because the root always occupies the first array position.

## 2. Two Rules of a Binary Heap

### 2.1 Complete Binary Tree Rule

Every level is completely filled except possibly the last level. Any values on the last level are placed from left to right without gaps.

This shape keeps the tree short. A Binary Heap containing N values has height `O(log N)`, so moving between the root and a leaf crosses only a small number of levels.

### 2.2 Heap Order Rule

The order rule depends on the Heap type:

- In a Min Heap, every parent is smaller than or equal to both children.
- In a Max Heap, every parent is greater than or equal to both children.

The rule applies at every parent. Repeated parent-child order places the minimum or maximum value at the root.

## 3. Heap is Not a Binary Search Tree

A Heap and a Binary Search Tree are both tree structures, but the ordering rules are different.

In a Binary Search Tree, values in the left subtree are smaller and values in the right subtree are larger. A Heap has no such left-versus-right rule. Both children only need to respect the parent.

For example, both children of a Min Heap root must be at least as large as the root. The left child does not need to be smaller than the right child. Because of this partial order, searching for an arbitrary value can take `O(N)` time.

## 4. Array Representation of a Binary Heap

A Binary Heap looks like a tree, but an array normally stores the values. The complete-tree shape guarantees that level-order storage has no empty positions between values.

For a **0-based array** and a node at index `i`:

- **Parent index:** `floor((i - 1) / 2)`
- **Left-child index:** `2 * i + 1`
- **Right-child index:** `2 * i + 2`

Consider the Min Heap array:

`[2, 5, 4, 9, 7, 8]`

| Index | Value | Parent | Left Child | Right Child |
|---:|---:|---:|---:|---:|
| 0 | 2 | None | 5 | 4 |
| 1 | 5 | 2 | 9 | 7 |
| 2 | 4 | 2 | 8 | None |
| 3 | 9 | 5 | None | None |
| 4 | 7 | 5 | None | None |
| 5 | 8 | 4 | None | None |

Every parent is smaller than both existing children, so the array represents a valid Min Heap.

![alt text](https://static.takeuforward.org/blogs/data-structure-and-algorithm/exec-cf847412-2ad4-4b32-922e-2dad734ac15e-c8c83b.webp)

## 5. Min Heap and Max Heap

### 5.1 Min Heap

In a Min Heap, every parent is smaller than or equal to its children. The smallest value stays at the root.

**Example:** `[2, 5, 4, 9, 7, 8]`

- Root `2` is smaller than `5` and `4`.
- Parent `5` is smaller than `9` and `7`.
- Parent `4` is smaller than `8`.

### 5.2 Max Heap

In a Max Heap, every parent is greater than or equal to its children. The largest value stays at the root.

**Example:** `[9, 7, 8, 2, 5, 4]`

- Root `9` is greater than `7` and `8`.
- Parent `7` is greater than `2` and `5`.
- Parent `8` is greater than `4`.

### 5.3 Min Heap vs Max Heap

| Point | Min Heap | Max Heap |
|---|---|---|
| Root contains | Smallest value | Largest value |
| Parent rule | Parent <= children | Parent >= children |
| Read root | `O(1)` | `O(1)` |
| Insert | `O(log N)` | `O(log N)` |
| Remove root | `O(log N)` | `O(log N)` |
| Common use | Minimum-priority processing | Maximum-priority processing |

## 6. Heapify

Heapify repairs the Heap order after a value moves into a position where the parent-child rule may be broken. Heapify does not sort the whole array. Heapify only moves the misplaced value along one path until the Heap becomes valid again.

Two directions are useful.

### 6.1 Heapify Up or Sift Up

Heapify up is mainly used after insertion. A new value first enters at the end of the array to preserve the complete-tree shape. The new value is then compared with its parent.

- In a Min Heap, a smaller child swaps with a larger parent.
- In a Max Heap, a larger child swaps with a smaller parent.

The process continues toward the root until the order becomes valid or the value reaches the root.

### 6.2 Heapify Down or Sift Down

Heapify down is mainly used after removing the root and during bottom-up Heap construction. A value near the top is compared with its children.

- In a Min Heap, the value swaps with the smaller child when the smaller child has a lower value.
- In a Max Heap, the value swaps with the larger child when the larger child has a higher value.

Choosing the correct child is important. A swap with the wrong child can leave the other parent-child relation invalid.

### 6.3 Dry Run of Max Heapify Down

![*Refer to the Max Heapify Down dry-run example.*](https://static.takeuforward.org/blogs/data-structure-and-algorithm/introduction-to-heap-max-heapify-down-dry-run-240af4.webp)

### 6.4 Heapify Complexity

- **Time Complexity:** `O(log N)` in the worst case, because a misplaced value can move through the full height of the complete binary tree.
- **Space Complexity:** `O(1)` for an iterative process, because only indexes and a temporary value are needed. A recursive process can use `O(log N)` call-stack space.

## 7. Build Heap

Build Heap converts an unordered array into a Min Heap or Max Heap. The efficient method treats the full array as a complete binary tree and repairs all parent nodes from bottom to top.

Every leaf is already a valid one-node Heap. For an array of size N, the last parent is at index:

`floor(N / 2) - 1`

Processing can begin there because later indexes are leaves.

### 7.1 Algorithm

1. Treat the complete array as a complete binary tree, because array positions already provide the required shape.
2. Find the last non-leaf index so unnecessary Heapify calls on leaves can be skipped.
3. Begin at the last non-leaf node, because both child subtrees below that node are already valid Heaps.
4. Apply Heapify down using the required Min Heap or Max Heap comparison.
5. Move one parent position to the left, because lower subtrees remain valid after every repair.
6. Continue until index `0` is repaired, making the full tree a valid Heap.

### 7.2 Dry Run

![alt text](https://static.takeuforward.org/blogs/data-structure-and-algorithm/introduction-to-heap-build-min-heap-dry-run-840423.webp)

### 7.3 Complexity Analysis

- **Time Complexity:** `O(N)`, because most nodes are near the leaves and can move only a small distance. Only a few nodes near the root can move through many levels.
- **Space Complexity:** `O(1)` for in-place construction with iterative Heapify. Recursive Heapify can use up to `O(log N)` call-stack space.

Building a Heap by inserting N values one at a time takes `O(N log N)`. Bottom-up Build Heap is faster for an existing array and takes `O(N)`.

## 8. Implementing a Min Heap

A Min Heap can be designed with a dynamic array and a stored size. The array holds the complete tree, while Heapify up and Heapify down protect the Min Heap order.

### 8.1 Min Heap Operations

#### Insert

Place the new value at the end of the array so the complete-tree shape remains valid. Compare the new value with its parent and keep swapping upward while the parent is larger.

**Time Complexity:** `O(log N)` for Heap repair. A dynamic-array resize can make one insertion take `O(N)`, while the normal amortized Heap insertion cost remains `O(log N)`.

#### Get Minimum

Read the value at index `0`. The Min Heap rule guarantees that the root contains the smallest value.

**Time Complexity:** `O(1)`.

#### Remove Minimum

Save the root value, move the last array value to the root, and remove the last position. Heapify down by repeatedly choosing the smaller child until Min Heap order returns.

**Time Complexity:** `O(log N)`.

#### Size and isEmpty

Return the stored number of values or compare the size with zero.

**Time Complexity:** `O(1)`.

### 8.2 Dry Run of Min Heap Insertion and Removal

![alt text](https://static.takeuforward.org/blogs/data-structure-and-algorithm/introduction-to-heap-min-heap-insertion-removal-dry-run-021fbc.webp)

## 9. Implementing a Max Heap

A Max Heap uses the same array layout and the same basic operations. Every comparison is reversed so larger values move upward and smaller values move downward.

### 9.1 Max Heap Operations

#### Insert

Place the new value at the end of the array. Compare the new value with its parent and keep swapping upward while the parent is smaller.

**Time Complexity:** `O(log N)` for Heap repair. A resizable backing array can occasionally add an `O(N)` resize to one insertion.

#### Get Maximum

Read the value at index `0`. The Max Heap rule guarantees that the root contains the largest value.

**Time Complexity:** `O(1)`.

#### Remove Maximum

Save the root value, move the last value to the root, and remove the final array position. Heapify down by repeatedly choosing the larger child until Max Heap order returns.

**Time Complexity:** `O(log N)`.

#### Size and isEmpty

Return the stored number of values or compare the size with zero.

**Time Complexity:** `O(1)`.

### 9.2 Dry Run of Max Heap Insertion and Removal

![alt text](https://static.takeuforward.org/blogs/data-structure-and-algorithm/introduction-to-heap-max-heap-insertion-removal-dry-run-6db6b0.webp)

## 10. Check Whether an Array is a Min Heap

An array represents a valid Min Heap when every parent is smaller than or equal to every existing child. A normal packed array already represents a complete tree, so only the order rule needs to be checked.

Leaves have no children and cannot break the rule. Only indexes from `0` through `floor(N / 2) - 1` need inspection.

### 10.1 Algorithm

1. Treat the array as a 0-based complete binary tree, because every occupied array position maps to one tree node.
2. Visit each non-leaf index, because leaves have no child relation to verify.
3. Compare the parent with the left child whenever the left child exists.
4. Return `false` immediately when the parent is greater than the left child, because Min Heap order has already failed.
5. Compare the parent with the right child whenever the right child exists.
6. Return `false` when the parent is greater than the right child; otherwise, finish all parent checks and return `true`.

### 10.2 Dry Run

![alt text](https://static.takeuforward.org/blogs/data-structure-and-algorithm/introduction-to-heap-check-min-heap-dry-run-674251.webp)

### 10.3 Complexity Analysis

- **Time Complexity:** `O(N)`, because at most half of the values are parents and each parent needs at most two child comparisons.
- **Space Complexity:** `O(1)`, because the array can be checked with only index and comparison variables.

## 11. Convert a Min Heap to a Max Heap

A Min Heap can be converted to a Max Heap without sorting the array. The old Min Heap order is no longer useful after the comparison direction changes, so the same array can be rebuilt with bottom-up Max Heapify.

The complete-tree shape already exists. Processing every non-leaf node from right to left changes only the order rule.

### 11.1 Algorithm

1. Keep the existing array layout, because the Min Heap already has the complete-tree shape required by a Max Heap.
2. Find the last non-leaf index so processing starts at the lowest parent.
3. Apply Max Heapify down at that parent, selecting the larger child whenever a swap is needed.
4. Move left through the remaining parent indexes, because repaired lower subtrees stay valid Max Heaps.
5. Continue Max Heapify down until the root at index `0` has been repaired.
6. Finish with the same values and same complete-tree shape, but with every parent greater than or equal to both children.

### 11.2 Dry Run

![alt text](https://static.takeuforward.org/blogs/data-structure-and-algorithm/introduction-to-heap-min-to-max-conversion-dry-run-7e5034.webp)

### 11.3 Complexity Analysis

- **Time Complexity:** `O(N)`, because the conversion is the same bottom-up process used by linear-time Build Heap.
- **Space Complexity:** `O(1)` for in-place conversion with iterative Max Heapify. Recursive Max Heapify can use up to `O(log N)` call-stack space.

## 12. Heap Operation Complexity Summary

| Operation | Time Complexity | Auxiliary Space | Main Idea |
|---|---|---|---|
| Read minimum from Min Heap | `O(1)` | `O(1)` | Read the root |
| Read maximum from Max Heap | `O(1)` | `O(1)` | Read the root |
| Insert | `O(log N)` | `O(1)` iterative | Add at the end and Heapify up |
| Remove root | `O(log N)` | `O(1)` iterative | Move last value to root and Heapify down |
| Heapify one node | `O(log N)` | `O(1)` iterative | Move along at most one root-to-leaf path |
| Build Heap | `O(N)` | `O(1)` iterative | Heapify all parents from bottom to top |
| Check Min Heap | `O(N)` | `O(1)` | Inspect every parent-child relation |
| Convert Min Heap to Max Heap | `O(N)` | `O(1)` iterative | Rebuild with bottom-up Max Heapify |
| Search for any value | `O(N)` | `O(1)` iterative | Heap order does not locate an arbitrary value |
| Store N values | — | `O(N)` total storage | The array stores all Heap elements |

The auxiliary-space values above assume iterative Heapify. Recursive Heapify can add `O(log N)` call-stack space.

## 13. Applications of Heaps

- **Priority queues:** The smallest or largest priority can be processed first.
- **Task scheduling:** Higher-priority tasks can be selected before lower-priority tasks.
- **Dijkstra's and Prim's algorithms:** A Min Heap can repeatedly provide the next smallest distance or edge.
- **Top K problems:** A small Heap can keep the most useful K values seen so far.
- **Heap Sort:** A Max Heap can repeatedly place the largest remaining value into its final array position.
- **Merge K sorted lists or arrays:** A Min Heap can expose the smallest current value among several sources.
- **Running median:** One Max Heap and one Min Heap can maintain the lower and upper halves of a stream.
- **Event simulation:** The event with the earliest time can be selected from a Min Heap.

## 14. Advantages and Limitations

### 14.1 Advantages

- The minimum or maximum value is available at the root in `O(1)` time.
- Insert and root removal take only `O(log N)` time.
- Bottom-up construction takes `O(N)` time.
- Array storage is compact and needs no child pointers.
- The complete-tree shape guarantees `O(log N)` height.

### 14.2 Limitations

- Only one extreme value is immediately available.
- Searching for an arbitrary value can take `O(N)` time.
- Heap order is partial, so the full array is not sorted.
- A Min Heap does not provide the maximum in constant time.
- A Max Heap does not provide the minimum in constant time.
- Equal-priority values do not have a guaranteed original order.
