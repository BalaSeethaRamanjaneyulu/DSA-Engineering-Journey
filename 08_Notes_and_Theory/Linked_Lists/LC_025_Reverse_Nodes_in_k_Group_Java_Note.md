# LC #025: Reverse Nodes in k-Group (Java Logic)

> **Pattern Card**: Recursive Sub-Structure Reversal
> **Goal**: Reverse nodes in fixed-size blocks of $k$ while maintaining list integrity for leftovers using object references.

---

## 🎤 The Interview Pitch
"In Java, I solve the 'Reverse k-Group' problem by blending iterative pointer reversal with a recursive structural skeleton. My logic first validates the existence of $k$ nodes. If found, it recursively calls for the next segment, then reverses the current $k$ nodes in-place, and finally links the current segment to the recursive result. This ensures $O(N)$ time efficiency while managing the complex reference updates cleanly through the stack."

---

## 🏗️ The Recursive Blueprint

1.  **Count & Validation**: We use a `count` variable and a temporary `curr` reference to verify that the next group has at least $k$ nodes.
2.  **Base Case**: If `count < k`, we return the `head` as-is (handling the incomplete last group).
3.  **Recursive Linkage**: Before reversing the current $k$ nodes, we anchor the result of the *next* group's reversal.
4.  **In-Place Swap**:
    ```java
    while (count-- > 0) {
        ListNode nextTemp = head.next;
        head.next = curr;
        curr = head;
        head = nextTemp;
    }
    ```

---

## ⚙️ Java Implementation Analysis

### Memory Locality
By performing the reversal in-place, we maximize cache efficiency and avoid the object creation overhead associated with auxiliary arrays or lists.

### Tail Recursion
While Java doesn't optimize tail recursion natively, the depth of this stack ($N/k$) is generally safe for typical list sizes in interview scenarios.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N/k)$ — Stack depth.

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_025_Reverse_Nodes_in_k_Group.java)
