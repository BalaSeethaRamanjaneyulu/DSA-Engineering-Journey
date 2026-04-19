# LC #142: Linked List Cycle II (C++ Logic)

> **Pattern Card**: Floyd's Cycle-Finding Algorithm (Phase 2)
> **Goal**: Not only detect if a cycle exists but locate the exact node where it begins.

---

## 🎤 The Interview Pitch
"In Linked List Cycle II, the challenge is to find the cycle's entrance in $O(1)$ space. I extend Floyd’s Tortoise and Hare algorithm into a two-phase strategy. Phase 1 detects the cycle and finds a meeting point. In Phase 2, I reset one pointer to the head and move both at the same speed. The point where they meet again is mathematically guaranteed to be the cycle entrance. This avoids the $O(N)$ space complexity of using a hash map."

---

## 📐 The Mathematical Proof (Phase 2)
Let:
- $L1$: Distance from head to cycle entrance.
- $L2$: Distance from entrance to meeting point.
- $C$: Total length of the cycle.

When slow and fast meet:
- Slow distance: $L1 + L2$
- Fast distance: $L1 + L2 + n \cdot C$ (where $n$ is number of laps)

Since $Fast\_dist = 2 \cdot Slow\_dist$:
$$L1 + L2 + n \cdot C = 2 \cdot (L1 + L2)$$
$$n \cdot C = L1 + L2$$
$$L1 = n \cdot C - L2$$

This equation ($L1 = (n-1) \cdot C + (C - L2)$) proves that the distance from the head to the entrance ($L1$) is equal to the distance from the meeting point to the entrance (considering cycle rotations).

---

## ⚙️ C++ Implementation Analysis

### Phase Transition
In C++, we capture the meeting point within the Phase 1 loop:
```cpp
if (slow == fast) {
    ListNode *entry = head;
    while (entry != slow) {
        entry = entry->next;
        slow = slow->next;
    }
    return entry;
}
```

### Safety & Edge Cases
- **No Cycle**: The `fast && fast->next` loop will terminate naturally and return `nullptr`.
- **N=1 Cycle**: Handled correctly as the meeting point and entrance are both the head.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_142_Linked_List_Cycle_II.cpp)
