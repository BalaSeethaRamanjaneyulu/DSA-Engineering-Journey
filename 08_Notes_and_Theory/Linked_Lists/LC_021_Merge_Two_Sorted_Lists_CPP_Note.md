# LC #021: Merge Two Sorted Lists (C++ Logic)

> **Pattern Card**: Dummy Node Technique
> **Goal**: Combine two sorted linked lists into a single sorted list efficiently.

---

## 🎤 The Interview Pitch
"To merge two sorted lists, I use an iterative approach with a **Dummy Node**. The dummy node serves as a placeholder for the head of the new list, allowing me to build the rest of the list without worrying about Special Case handling for the head pointer itself. We compare the values of the two lists node-by-node and simply 're-wire' the pointers to the smaller element, achieving $O(M+N)$ time complexity."

---

## 🏗️ The Dummy Node Advantage
In C++, managing pointers can be tricky. Without a dummy node, we would have to write extra logic to determine which node becomes the `head` (checking `if (l1->val < l2->val)` before the main loop).
By using `ListNode dummy(0);`, we skip that. `dummy.next` will automatically point to the correct head once the merging is complete.

---

## ⚙️ C++ Implementation Analysis

### Memory Management
- **In-place Re-wiring**: We do not create new nodes (except for the dummy). We simply change the `next` pointers of existing nodes. This makes the space complexity $O(1)$.
- **Trailing Cleanup**: Once one list is exhausted, the remaining elements of the other list are already sorted and linked. We just need to attach the tail of our merged list to the start of the remaining list.

### Complexity Breakdown
- **Time Complexity**: $O(M + N)$ where $M, N$ are lengths of the lists.
- **Space Complexity**: $O(1)$ (ignoring the dummy node on the stack).

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_021_Merge_Two_Sorted_Lists.cpp)
