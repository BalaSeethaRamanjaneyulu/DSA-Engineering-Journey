# LC #023: Merge k Sorted Lists (Python Logic)

> **Pattern Card**: Min-Heap (heapq)
> **Goal**: Synchronize multiple sorted streams using a priority queue.

---

## 🎤 The Interview Pitch
"In Python, the most efficient way to merge $k$ sorted lists is by using the `heapq` module. By feeding the head of each list into a Min-Heap, we can iteratively extract the smallest available element across all lists in $O(\log k)$ time. This approach maintains an $O(N \log k)$ time complexity while keeping the memory footprint at $O(k)$, making it the standard industry approach for merging large datasets or processing sorted logs from multiple sources."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Data Structure**| `mergeKListsHelper` | `PriorityQueue` | **`heapq`** |
| **Logic** | Divide & Conquer | Min-Heap | **Min-Heap** |
| **Complexity Cache**| Recursive Stack | Explicit PQ Object | **Tuple/Heap Engine** |

### Why Python’s `heapq` is Unique?
In Python, `heapq` is a collection of min-heap functions on a standard list. To make it work with `ListNode` objects, we often need to:
1.  **Use Tuples**: `(node.val, i, node)` where `i` is a unique index to break ties and avoid comparing nodes directly.
2.  **Define `__lt__`**: Alternatively, defining the "less than" operator inside the `ListNode` class allows the heap to compare nodes based on their values automatically. In our implementation, we used the `__lt__` approach for maximum code cleanliness.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N \log k)$
- **Space Complexity**: $O(k)$ — To maintain the heap of $k$ list heads.

---
[View Python Code](../../01_Data_Structures/Linked_List/LC_023_Merge_k_Sorted_Lists.py)
