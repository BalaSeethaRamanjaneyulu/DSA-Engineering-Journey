# LC #143: Reorder List (Python Logic)

> **Pattern Card**: Middle + Reverse + Merge
> **Goal**: Reorder a list to interleave head and tail nodes in-place.

---

## 🎤 The Interview Pitch
"In Python, the 'Reorder List' problem is a beautiful exercise in linked list modularity. I solve it by combining three fundamental patterns: finding the middle using tortoise-and-hare pointers, reversing the second segment in-place, and finally stitching the two segments together. This approach guarantees $O(N)$ time complexity and, crucially, $O(1)$ space, making it vastly superior to naive array-based strategies."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Pointers** | Raw Pointers (`ListNode*`) | Object References | Object References |
| **Logic** | Explicit Nullptr Checks | Null Checks | **Pythonic Tuple Unpacking** |
| **Readability**| Mid-tier | Detailed but Verbose | **Expert Level** |

### Why Python is "Better" for this Problem?
Python's **Tuple Unpacking** (e.g., `first, second = tmp1, tmp2`) significantly reduces the cognitive load during the merge phase. In C++ or Java, managing these three or four moving pointers often lead to confusion or "pointer soup." Python's expressive syntax allows the algorithm's intent to shine through clearly.

---

## 🎨 Dry Run Trace (Pythonic View)
Let's trace the alternating merge for `First [1, 2, 3]` and `Second [5, 4]`.

| Iteration | First Pointer | Second Pointer | Action | List State |
| :--- | :--- | :--- | :--- | :--- |
| **Init** | `1` | `5` | Prepare variables | `1 ... 2 ... 3`, `5 ... 4` |
| **1** | `1` | `5` | `1.next = 5`, `5.next = 2` | `1 -> 5 -> 2 ... 3`, `4` |
| **2** | `2` | `4` | `2.next = 4`, `4.next = 3` | `1 -> 5 -> 2 -> 4 -> 3` |

**Final Result**: `1 -> 5 -> 2 -> 4 -> 3` (Linked list tail automatically ends correctly at `3`).

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(1)$

---
[View Python Code](../../01_Data_Structures/Linked_List/LC_143_Reorder_List.py)
