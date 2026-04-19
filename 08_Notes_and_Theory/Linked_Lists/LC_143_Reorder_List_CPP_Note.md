# LC #143: Reorder List (C++ Logic)

> **Pattern Card**: Middle + Reverse + Merge
> **Goal**: Reorder a linked list to interleave nodes from the front and back.

---

## 🎤 The Interview Pitch
"To reorder a linked list in $O(N)$ time and $O(1)$ space, I break the problem into three modular steps. First, I find the list's middle using the Fast and Slow pointer technique. Second, I reverse the entire second half of the list in-place. Finally, I merge the two resulting halves alternatingly. This approach avoids the $O(N)$ space required by an array-based solution while maintaining linear performance."

---

## 🏗️ The 3-Step Strategy
Reordering `[1 -> 2 -> 3 -> 4 -> 5]` into `[1 -> 5 -> 2 -> 4 -> 3]` requires three distinct operations:

### 1. Finding the Pivot
Using `slow` and `fast` pointers, we find the middle node.
- If $N=5$, `slow` stops at `3`.
- We split the list into `[1 -> 2 -> 3]` and `[4 -> 5]`.

### 2. The In-Place Reversal
We reverse the second half `[4 -> 5]` to get `[5 -> 4]`. This uses the standard 3-pointer reversal method.

### 3. Alternating Merge
We now have two heads: `Head1 (1)` and `Head2 (5)`.
- Step 1: `1 -> 5`
- Step 2: `5 -> 2`
- Step 3: `2 -> 4`
- Step 4: `4 -> 3`

---

## ⚙️ C++ Implementation Analysis

### Modular Logic
By separating the logic into Middle, Reverse, and Merge, the C++ implementation remains highly readable and easy to debug.

### Memory Optimization
Since we are only re-wiring the `next` pointers of existing nodes, we allocate zero additional memory for the nodes themselves, achieving the optimal $O(1)$ space complexity.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_143_Reorder_List.cpp)
