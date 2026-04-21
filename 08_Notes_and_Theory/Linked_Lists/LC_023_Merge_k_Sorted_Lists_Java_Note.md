# LC #023: Merge k Sorted Lists (Java Logic)

> **Pattern Card**: Min-Heap (PriorityQueue)
> **Goal**: Stream merge multiple sorted sources using a heap-based scheduler.

---

## 🎤 The Interview Pitch
"In Java, merging $k$ sorted lists is most elegantly solved using a `PriorityQueue`. By maintaining a Min-Heap of the 'current' heads of all $k$ lists, we can always extract the absolute smallest node across all sources in $O(\log k)$ time. This turns the merge process into a stream-like execution where we process $N$ total nodes in $O(N \log k)$ time. It is a highly scalable pattern for combining data from multiple sorted streams."

---

## 🏗️ The Heap-Based Logic

1.  **Initialization**: Insert the head node of each of the $k$ lists into the `PriorityQueue`.
2.  **Extraction**: Extract the node with the minimum value. Attach it to our result list.
3.  **Replenishment**: If the extracted node has a `next` pointer, insert that next node into the heap.
4.  **Termination**: Continue until the heap is empty.

### Why PriorityQueue?
It abstracts the complex task of "finding the minimum among $k$ values" into a single function call (`pq.poll()`). This reduces code complexity and minimizes the risk of off-by-one errors compared to a manual pointer-array management.

---

## ⚙️ Java Implementation Analysis

### Lambda Comparators
We use a modern lambda expression for the PQ initialization:
```java
PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
```
This is a clean, readable way to define the ordering criteria for the heap.

### Memory Overhead
The `PriorityQueue` stores at most $k$ references at any given time. This results in $O(k)$ auxiliary space complexity. While Divide and Conquer can achieve $O(\log k)$ on the stack, the Min-Heap is often preferred for its **Online/Streaming** nature.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N \log k)$
- **Space Complexity**: $O(k)$ — To store the heads of the $k$ lists in the heap.

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_023_Merge_k_Sorted_Lists.java)
