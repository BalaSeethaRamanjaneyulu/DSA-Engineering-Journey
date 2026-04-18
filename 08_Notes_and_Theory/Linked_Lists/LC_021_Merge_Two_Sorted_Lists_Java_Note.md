# LC #021: Merge Two Sorted Lists (Java Logic)

> **Pattern Card**: Dummy Node Technique
> **Goal**: Seamlessly combine two sorted object-reference paths into one.

---

## 🎤 The Interview Pitch
"In Java, I use an iterative approach with a `dummy` ListNode to merge two sorted lists. The dummy node serves as a fixed anchor, allowing the `tail` pointer to consistently link the smaller node from either list. This approach is highly memory-efficient as it performs an in-place merge by re-pointing existing references, avoiding the creation of new node objects."

---

## 🏗️ The Dummy Node Advantage (Java Perspective)
In Java, managing the head of a list often requires a null-check. By using `ListNode dummy = new ListNode(0);`, we eliminate the need for an initial `if-else` block to assign the `head`. 
-   **Before Dummy Node**: `head = (l1.val < l2.val) ? l1 : l2;` (plus null checks for l1/l2).
-   **After Dummy Node**: We just start the loop. It makes the code cleaner and more robust for interviews.

---

## ⚙️ Java Implementation Analysis

### Reference Manipulation
Instead of creating `new ListNode(curr.val)`, we simply assign `tail.next = list1;`. This leverages Java's reference model to achieve **O(1) extra space**. We are literally moving the nodes from the original lists into the merged list.

### Defensive Programming
The `while (list1 != null && list2 != null)` loop ensures we only compare when both lists have valid data. Once one list is null, the ternary operator `tail.next = (list1 != null) ? list1 : list2;` efficiently attaches the entire remaining sequence of the other list.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(M + N)$
- **Space Complexity**: $O(1)$ (In-place merge).

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_021_Merge_Two_Sorted_Lists.java)
