# LC #141: Linked List Cycle (C++ Logic)

> **Pattern**: Fast and Slow Pointers (Floyd's Cycle-Finding Algorithm)

---

## 🎤 The Interview Pitch
"To detect a cycle in a singly linked list with $O(1)$ space, I use Floyd’s Cycle-Finding algorithm. By moving a 'fast' pointer two steps for every one step of a 'slow' pointer, I guarantee that if a cycle exists, the fast pointer will eventually 'lap' the slow pointer from behind and they will meet at the same node. This avoids the $O(N)$ space required by a hash set."

---

## 🎨 Logic Visualization (C++)

Implication of the **2-Step vs 1-Step** Movement:
Imagine two runners on a circular track. Even if one starts behind, the faster runner will eventually catch the slower one by completing one more lap.

```mermaid
graph LR
    A((3)) --> B((2))
    B --> C((0))
    C --> D((-4))
    D --> B
    style B fill:#f96,stroke:#333
    subgraph Cycle detection
    direction LR
    S[Slow ptr: +1 step]
    F[Fast ptr: +2 steps]
    end
```

### Why it works (Mathematical Intuition):
If the distance between the two pointers in the cycle is $D$, then with each step, the fast pointer closes the gap by exactly 1 ($2 - 1 = 1$). Therefore, they are guaranteed to meet in exactly $D$ steps after entering the cycle.

---

## ⚙️ C++ Implementation Details
In C++, we must be careful with defensive programming regarding `nullptr`:
- Check `!head` and `!head->next` immediately.
- The loop condition `while (fast && fast->next)` ensures that `fast->next->next` is always a safe operation.

### Complexity Analysis
- **Time**: $O(N)$ — In the worst case (no cycle), we traverse the list once. With a cycle, the fast pointer completes at most one extra lap.
- **Space**: $O(1)$ — Only two auxiliary pointers are used.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_141_Linked_List_Cycle.cpp)
