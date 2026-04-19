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
| **LC #141: Linked List Cycle** | Easy | Fast & Slow Pointers | [C++](LC_141_Linked_List_Cycle.cpp), [Java](LC_141_Linked_List_Cycle.java), [Python](LC_141_Linked_List_Cycle.py) |
| **LC #142: Linked List Cycle II** | Medium | Floyd's Phase 2 | [C++](LC_142_Linked_List_Cycle_II.cpp), [Java](LC_142_Linked_List_Cycle_II.java), [Python](LC_142_Linked_List_Cycle_II.py) |
| **LC #021: Merge Two Sorted Lists**| Easy | Dummy Node Technique | [C++](LC_021_Merge_Two_Sorted_Lists.cpp), [Java](LC_021_Merge_Two_Sorted_Lists.java), [Python](LC_021_Merge_Two_Sorted_Lists.py) |
| **LC #143: Reorder List** | Medium | Middle + Reverse + Merge | [C++](LC_143_Reorder_List.cpp), [Java](LC_143_Reorder_List.java), [Python](LC_143_Reorder_List.py) |
| **LC #019: Remove Nth Node From End**| Medium | Two Pointers (Gap) | [C++](LC_019_Remove_Nth_Node_From_End.cpp), [Java](LC_019_Remove_Nth_Node_From_End.java), [Python](LC_019_Remove_Nth_Node_From_End.py) |
| **LC #138: Copy List with Random Pt**| Medium | Node Interweaving | [C++](LC_138_Copy_List_Random_Pointer.cpp), [Java](LC_138_Copy_List_Random_Pointer.java), [Python](LC_138_Copy_List_Random_Pointer.py) |

---

## Essential Patterns

### 1. The Three-Pointer Technique
Used for in-place reversal. Maintain `prev`, `curr`, and `next_temp`.

### 2. Fast and Slow Pointers (Tortoise and Hare)
- **Middle of List**: Slow moves 1 step, Fast moves 2 steps.
- **Cycle Detection**: If Fast caught up to Slow, a cycle exists.
- **K-th node from end**: Move Fast $K$ steps ahead, then move both at same speed.

### 3. Dummy Node Technique
Extremely useful for handling edge cases where the head of the list might be deleted or modified.

### 4. Node Interweaving
Used for deep copying lists with complex pointers. Temporarily inserts copy nodes between original nodes to keep relationship mapping in $O(1)$ space.

---

> *"The beauty of Linked Lists lies in their dynamic nature, allowing for constant-time insertions and deletions if the position is known."*
