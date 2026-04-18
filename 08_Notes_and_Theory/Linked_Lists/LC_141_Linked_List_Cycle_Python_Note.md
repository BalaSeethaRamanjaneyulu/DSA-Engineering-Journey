# LC #141: Linked List Cycle (Python Logic)

> **Pattern Card**: Fast & Slow Pointers (Two-Pointer Technique)
> **Goal**: Detect if a singly linked list contains a cycle without extra storage.

---

## 🎤 The Interview Pitch
"In Python, I leverage Floyd's Tortoise and Hare algorithm to detect cycles in $O(1)$ space. By advancing two object references at different speeds, I can determine if they eventually collide. Python's dynamic typing and object reference model make the code incredibly clean, while allowing us to skip the heavy memory overhead of a hash-based approach."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Pointers** | Raw Pointers (`ListNode*`) | Object References | Object References |
| **Null Safety** | Manual `!head` check | Manual `null` check | Pythonic `not head` |
| **Logic Suitability** | High performance for large $N$ | Strongly-typed safety | **Winner for Readability** |

### Why Python is "Better" for this Problem?
For cycle detection, Python is exceptionally clean because:
1.  **Reference Comparison**: The `slow == fast` check is a direct reference comparison in Python, which is intuitive.
2.  **Conciseness**: The logic fits in just a few lines of code without curly-brace noise, which is great for quick technical interviews.
3.  **Prototyping**: Setting up test cases with cycles (as seen in our driver) is faster in Python due to list comprehensions and flexible object creation.

---

## 🎨 Dry Run Trace
Let's trace a list with a cycle: `[3 -> 2 -> 0 -> -4]` where `-4` points back to `2`.

| Step | Slow Pointer | Fast Pointer | Gap Status |
| :--- | :--- | :--- | :--- |
| **Start** | `node(3)` | `node(3)` | Distance: 0 |
| **Iteration 1**| `node(2)` | `node(0)` | Distance: 1 |
| **Iteration 2**| `node(0)` | `node(2)` (via cycle) | Distance: 1 (Lapping) |
| **Iteration 3**| `node(-4)`| `node(-4)` | **COLLISION** |

**Result**: Return `True`.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(1)$

---
[View Python Code](../../01_Data_Structures/Linked_List/LC_141_Linked_List_Cycle.py)
