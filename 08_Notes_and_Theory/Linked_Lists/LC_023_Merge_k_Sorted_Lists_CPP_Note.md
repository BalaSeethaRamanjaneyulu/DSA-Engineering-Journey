# LC #023: Merge k Sorted Lists (C++ Logic)

> **Pattern Card**: Divide and Conquer (Merge Sort Paradigm)
> **Goal**: Efficiently combine $k$ sorted lists into a single sorted list.

---

## 🎤 The Interview Pitch
"Merging $k$ sorted lists is a classic optimization problem. While a naive approach would be to merge lists one by one ($O(N \cdot k)$), I use the **Divide and Conquer** strategy to achieve a complexity of $O(N \log k)$. This reduces the height of the 'merge tree' and ensures that every node is processed only $\log k$ times. In C++, this can be implemented recursively or iteratively to maintain a clean memory footprint while utilizing the standard two-list merge helper."

---

## 🏗️ The Divide and Conquer strategy
Instead of linear merging, we pair the lists and merge them:
- Level 0: 8 lists
- Level 1: 4 lists (merged from pairs)
- Level 2: 2 lists
- Level 3: 1 final list

### Why not Min-Heap?
In C++, `std::priority_queue` is another valid $O(N \log k)$ approach. However:
1.  **Divide and Conquer** uses $O(1)$ auxiliary space if implemented iteratively (or $O(\log k)$ recursively).
2.  **Min-Heap** always requires $O(k)$ auxiliary space to store the current head nodes.
3.  Divide and Conquer is often easier to implement during an interview as it reuses the "Merge Two Sorted Lists" building block.

---

## ⚙️ C++ Implementation Analysis

### Reusing the Building Block
The function `mergeTwoLists(l1, l2)` is our workhorse. By ensuring this helper is $O(1)$ space and uses the **Dummy Node** technique, the overall solution remains robust.

### Recursive Depth
The `mergeKListsHelper` uses a range-based split (`mid = start + (end - start) / 2`). This ensures that the recursion tree is balanced, keeping the stack depth at exactly $O(\log k)$.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N \log k)$
  - Each of the $N$ total nodes is moved exactly $\log k$ times.
- **Space Complexity**: $O(\log k)$
  - Recursion stack depth. Can be $O(1)$ if converted to an iterative pairing loop.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_023_Merge_k_Sorted_Lists.cpp)
