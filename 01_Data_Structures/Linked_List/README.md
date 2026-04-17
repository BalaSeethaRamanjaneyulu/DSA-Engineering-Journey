# Linked List Concepts and Patterns

> "A Linked List is a linear data structure where elements are not stored at contiguous memory locations. Instead, elements are linked using pointers."

---

## Core Structure

### Singly Linked List
```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

### Key Operations Complexity
| Operation | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Access/Search** | $O(N)$ | Must traverse from head. |
| **Insertion (at head)** | $O(1)$ | Simple pointer re-assignment. |
| **Deletion (at head)**| $O(1)$ | Simple pointer re-assignment. |
| **Insertion/Deletion (middle)** | $O(N)$ | Requires search first. |

---

## Problem Set and Progress

| Problem | Difficulty | Key Pattern | Solutions |
| :--- | :--- | :--- | :--- |
| **LC #206: Reverse Linked List** | Easy | Three Pointers (Iterative) | [C++](LC_206_Reverse_Linked_List.cpp), [Java](LC_206_Reverse_Linked_List.java), [Python](LC_206_Reverse_Linked_List.py) |

---

## Essential Patterns

### 1. The Three-Pointer Technique
Used for in-place reversal. Maintain `prev`, `curr`, and `next_temp`.

### 2. Fast and Slow Pointers (Tortoise and Hare)
- **Middle of List**: Slow moves 1 step, Fast moves 2 steps.
- **Cycle Detection**: If Fast caught up to Slow, a cycle exists.
- **K-th node from end**: Move Fast $K$ steps ahead, then move both at same speed.

### 3. Dummy Node Technique
Extremely useful for problems involving creating a new list or deleting nodes (handles edge cases where head is deleted).

---

> *"The beauty of Linked Lists lies in their dynamic nature, allowing for constant-time insertions and deletions if the position is known."*
