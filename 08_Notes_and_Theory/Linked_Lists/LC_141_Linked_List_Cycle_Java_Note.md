# LC #141: Linked List Cycle (Java Logic)

> **Pattern**: Fast and Slow Pointers (Floyd's Algorithm)

---

## 🎤 The Interview Pitch
"In Java, I implement Floyd’s cycle-finding algorithm to ensure O(1) auxiliary space. By using two reference pointers—a 'slow' one traversing one node at a time and a 'fast' one traversing two—I can detect if a cycle exists by checking if the references eventually point to the same object in memory. This is highly efficient and avoids the overhead of a `HashSet`."

---

## ⚙️ Java Implementation Analysis

### Reference Equality
In Java, the check `if (slow == fast)` compares the reference (memory address) of the objects. Since a cycle causes the pointers to traverse the same set of nodes indefinitely, the fast pointer is guaranteed to eventually point to the same object as the slow pointer.

### Null Safety
The core of the loop defensive check in Java is:
```java
while (fast != null && fast.next != null) { ... }
```
- If `fast` becomes `null`, it means we've reached the end of the list (No cycle).
- If `fast.next` is `null`, it also means the end (No cycle).
- This prevents `NullPointerException` when calling `fast.next.next`.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
  - Let $N$ be the number of nodes. 
  - If no cycle: $N$ steps.
  - If cycle: The fast pointer enters the cycle and catches the slow pointer in less than $N$ iterations.
- **Space Complexity**: $O(1)$
  - Only two object references (`slow`, `fast`) are maintained regardless of list size.

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_141_Linked_List_Cycle.java)
