# LC #019: Remove Nth Node From End (Java Logic)

> **Pattern Card**: Two-Pointer (Gap) Technique + Dummy Node
> **Goal**: Interleave reference movement to perform removal in a single pass.

---

## 🎤 The Interview Pitch
"In Java, I optimize the 'Remove Nth Node' problem by using a one-pass algorithm that eliminates the need to calculate the list length first. By maintaining a fixed-size window between two object references (`first` and `second`), I can locate the target node relative to the tail. The use of a Dummy Node is key here, as it provides a safe reference to the head and simplifies the case where the N-th node from the end is the head itself."

---

## 🏗️ The Dummy Node Utility
In Java, modifying the head of a linked list is a common source of bugs. By using `ListNode dummy = new ListNode(0)`, we create a permanent anchor.
-   If we have 5 nodes and $N=5$, we need to remove the head.
-   Without a dummy node, we'd need an `if (n == length)` check.
-   With a dummy node, the `second` pointer simply stays at the dummy, and `second.next = second.next.next` correctly updates the head reference for us.

---

## ⚙️ Java Implementation Analysis

### The Windowing Mechanism
```java
// Move 'first' to create a gap of n nodes
for (int i = 0; i <= n; i++) {
    first = first.next;
}
```
This loop prepares the `first` pointer such that there are exactly $n$ nodes between `first` and `second`. As both move forward at the same speed, this distance remains constant.

### Garbage Collection
Unlike C++, Java developers don't need to manually `delete` the skipped node. Java’s Garbage Collector will automatically recover the memory once the node is no longer reachable from any part of the list.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(1)$

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_019_Remove_Nth_Node_From_End.java)
