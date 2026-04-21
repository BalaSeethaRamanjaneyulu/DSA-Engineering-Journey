# LC #025: Reverse Nodes in k-Group (C++ Logic)

> **Pattern Card**: Recursive Sub-Structure Reversal
> **Goal**: Reverse nodes in fixed-size blocks of $k$ while maintaining list integrity for leftovers.

---

## 🎤 The Interview Pitch
"Reversing nodes in $k$-groups is a classic Hard problem that tests pointer manipulation and recursion depth. My approach uses a recursive backbone: I first check if a group of size $k$ exists. If it does, I reverse that block in-place using a 3-pointer technique and then recursively link its tail to the result of the next $k$-group reversal. This ensures that the overall list is transformed in $O(N)$ time with $O(N/k)$ space, handling the 'incomplete last group' edge case perfectly."

---

## 🏗️ The Recursive Blueprint

1.  **Lookahead**: Traverse $k$ nodes forward. If you hit `nullptr` before $k$, return the current head (don't reverse).
2.  **Recursion**: Call `reverseKGroup` on the $(k+1)$-th node to get the new 'tail' link.
3.  **In-Place Reverse**: Reverse the current $k$ nodes. The original `head` becomes the tail of this segment and points to the result of Step 2.

### C++ Syntax Note
In C++, we must be careful with pointer re-assignments. By using local `next_temp` variables inside the reversal loop, we keep the data structure consistent at every step.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$ — Each node is visited exactly twice (once for lookahead, once for reversal).
- **Space Complexity**: $O(N/k)$ — Recursion stack depth.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_025_Reverse_Nodes_in_k_Group.cpp)
