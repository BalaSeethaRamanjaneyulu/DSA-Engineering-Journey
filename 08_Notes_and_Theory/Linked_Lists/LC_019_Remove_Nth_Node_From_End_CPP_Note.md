# LC #019: Remove Nth Node From End (C++ Logic)

> **Pattern Card**: Two-Pointer (Gap) Technique + Dummy Node
> **Goal**: Remove a node at a specific position relative to the tail in a single pass.

---

## 🎤 The Interview Pitch
"To remove the N-th node from the end of a linked list in $O(N)$ time and $O(1)$ space, I use the Two-Pointer Gap technique. Unlike a naive two-pass approach that first calculates the list length, this method uses a 'first' and 'second' pointer separated by exactly $N$ nodes. When the first pointer reaches the end, the second pointer will be positioned exactly at the node *preceding* the target. By using a Dummy Node, we naturally handle the edge case where the head itself needs to be removed."

---

## 🏗️ The Two-Pointer Logic
Removing the 2nd node from the end of `[1 -> 2 -> 3 -> 4 -> 5]`:

1.  **Gap Creation**: Move the `first` pointer $N+1$ steps ahead of `second`.
    - Gap $= 3$ steps (including dummy).
2.  **Maintaining the Gap**: Move both pointers one step at a time until `first` hits `nullptr`.
3.  **Removal**: The `second` pointer now points to `3`. The node to delete is `second->next` (which is `4`).
4.  **Re-wiring**: `3->next = 3->next->next` (skips `4`).

---

## ⚙️ C++ Implementation Analysis

### The Dummy Node
In C++, stack-allocating a `ListNode dummy(0)` is an efficient way to handle lists of length 1 or cases where $N = \text{length}$. It ensures that `second->next` is always the node we want to remove, even if that node is the original head.

### Memory Integrity
To avoid memory leaks in a production-grade C++ environment, we explicitly capture the pointer to the target node (`ListNode* to_delete`) and use the `delete` operator after re-wiring.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$ — Single pass traversal.
- **Space Complexity**: $O(1)$ — Only two auxiliary pointers used.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_019_Remove_Nth_Node_From_End.cpp)
