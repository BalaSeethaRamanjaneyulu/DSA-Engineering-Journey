# LC #143: Reorder List (Java Logic)

> **Pattern Card**: Middle + Reverse + Merge
> **Goal**: Interleave a linked list's nodes from start and end using in-place reference manipulation.

---

## 🎤 The Interview Pitch
"In Java, I optimize the reorder list problem by performing an in-place transformation that avoids the $O(N)$ space overhead of an auxiliary list. The strategy involves identifying the midpoint using Fast/Slow pointers, reversing the tail half of the list to allow back-to-front access, and finally performing a single-pass merge to stitch the nodes into their new configuration. This ensures $O(N)$ time and $O(1)$ space efficiency."

---

## ⚙️ Java Implementation Analysis

### Reference Management
The key to avoiding `NullPointerException` during the merge phase is the conditional logic `while (second != null)`. Since we split the list at the middle, the second half will always be equal to or one node shorter than the first half, depending on whether $N$ is even or odd.

### Step-by-Step Breakdown

1.  **Midpoint Search**: `while (fast.next != null && fast.next.next != null)`
    - This stops `slow` exactly where the first half ends.
2.  **Splitting**: `slow.next = null`
    - Crucial step to create two independent sub-lists.
3.  **In-Place Reverse**: Standard iterative reversal on the `second` half.
4.  **Alternating Merge**: Use temporary local variables (`tmp1`, `tmp2`) to hold the references to the remaining list segments while re-pointing the `next` links.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
  - $N/2$ to find middle + $N/2$ to reverse + $N$ to merge.
- **Space Complexity**: $O(1)$
  - Only constant extra space for local object references.

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_143_Reorder_List.java)
