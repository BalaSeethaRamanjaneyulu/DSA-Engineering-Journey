# LC #739: Daily Temperatures (C++ Logic)

> **Pattern Card**: Monotonic Stack (Decreasing)
> **Goal**: Efficiently find the first greater element to the right in a linear sequence.

---

## 🎤 The Interview Pitch
"Finding the next warmer day manually would require a nested loop ($O(N^2)$), which is inefficient for large datasets. Instead, we use a **Monotonic Stack** to maintain indices of temperatures that haven't found a warmer match yet. By keeping the stack in a strictly decreasing order of temperatures, we can instantly identify the 'waiting period' for multiple previous days as soon as a warmer temperature appears. This approach processes each element at most twice (one push, one pop), resulting in a highly optimized $O(N)$ time complexity."

---

## 🏗️ The Logic Engine: Monotonicity

A **Monotonic Decreasing Stack** ensures that elements are stored from largest to smallest.
- **Rule**: Before pushing a new index `i`, we pop all indices `j` from the stack where `temperatures[i] > temperatures[j]`.
- **Result**: For every popped index `j`, the current index `i` is its **Next Greater Element**. The difference `i - j` is the distance (days) we were looking for.

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Logic** | `std::stack<int>` | `java.util.Stack` | **List `[]`** |
| **Storage** | Indices | Indices | **Indices** |
| **Efficiency** | **Winner (Native)** | High | Best Expressiveness |

### Why C++ for Monotonic Stacks?
C++'s `std::stack` over `std::vector` indices provides a clear semantic intent. In performance-critical systems, using a fixed-size array as a stack can further reduce overhead, but the STL `stack` is the gold standard for interview-grade correctness and readability.

---

## 🎨 Logic Visualization (Mermaid)
Input: `[73, 74, 75, 71]`

```mermaid
graph LR
    subgraph Stack State
    S1[73 at index 0]
    S2[74 at index 1]
    S3[75 at index 2]
    S4[71 at index 3]
    end
    Note over S1: 74 > 73? Yes! Pop 0. Res[0] = 1-0 = 1.
    Note over S2: 75 > 74? Yes! Pop 1. Res[1] = 2-1 = 1.
    Note over S3,S4: 71 < 75. Push 3. Stack contains indices [2, 3]
```

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$ — Each element is pushed and popped exactly once.
- **Space Complexity**: $O(N)$ — In the worst case (strictly decreasing temperatures), the stack stores all indices.

---
[View C++ Code](../../01_Data_Structures/Stack/LC_739_Daily_Temperatures.cpp)
