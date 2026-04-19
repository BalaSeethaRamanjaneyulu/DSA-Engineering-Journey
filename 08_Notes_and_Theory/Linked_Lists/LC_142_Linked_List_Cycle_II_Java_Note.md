# LC #142: Linked List Cycle II (Java Logic)

> **Pattern Card**: Floyd's Cycle Detection (Phase 1 & 2)
> **Goal**: Detect cycle and identify the entry node using object reference comparison.

---

## 🎤 The Interview Pitch
"In Java, I implement a two-phase Floyd’s cycle detection algorithm to handle the Cycle II problem. Phase 1 uses a fast and slow reference to confirm the cycle exists and identify a meeting point. Phase 2 leverages the mathematical distance from the head to the entrance to finalize the search. Using $O(1)$ space is the highlight here, as it avoids the substantial memory overhead of a `HashSet` in high-scale systems."

---

## ⚙️ Java Implementation Analysis

### Reference Comparison
In Java, the `==` operator on object references (like `ListNode`) compares the memory address of the nodes. This is the foundation of Floyd’s algorithm:
```java
if (slow == fast) { // They point to the exact same object
    ListNode entry = head;
    while (entry != slow) {
        entry = entry.next;
        slow = slow.next;
    }
    return entry;
}
```

### Safety & Robustness
The loop condition `while (fast != null && fast.next != null)` is the standard defensive check in Java to prevent `NullPointerException` when the list is short or does not contain a cycle.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
  - Phase 1: At most $N$ steps to meet.
  - Phase 2: At most $N$ steps to reach the entrance from head.
- **Space Complexity**: $O(1)$
  - Only two/three auxiliary references maintained throughout the process.

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_142_Linked_List_Cycle_II.java)
