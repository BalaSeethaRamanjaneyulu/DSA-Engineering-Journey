# LC #155: Min Stack (C++ Logic)

> **Pattern Card**: Auxiliary State Persistence (Two-Stack Method)
> **Goal**: Design a stack that provides the minimum element in $O(1)$ time without sacrificing standard operation efficiency.

---

## 🎤 The Interview Pitch
"To retrieve the minimum element of a stack in constant time, we must maintain a 'running history' of the minimums alongside our data. A simple variable isn't enough because once the current minimum is popped, we lose track of the *previous* minimum. By using a second auxiliary stack (the `Min Stack`), we can store the minimum value encountered up to each level of the main stack. This ensures that every `pop` operation correctly reverts both the data and the minimum state in $O(1)$ time."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Encapsulation** | `class MinStack` | `class MinStack` | **`class MinStack`** |
| **Logic** | Two `std::stack` | Two `java.util.Stack`| **One List of Tuples** |
| **Efficiency** | **Winner (Memory)** | High | Best Versatility |

### Why C++ for this Design?
C++ allows for precise control over stack objects. By using two `std::stack<int>`, we keep the logic decoupled and clear. Additionally, C++'s RAII (Resource Acquisition Is Initialization) and destructor support ensure that memory is managed efficiently if we were to use custom node objects instead of STL stacks.

---

## 🎨 Logic Visualization (Mermaid)
Sequence: `Push(-2)`, `Push(0)`, `Push(-3)`, `Pop()`

```mermaid
graph LR
    subgraph Data Stack
    D1[-2]
    D2[0]
    D3[-3]
    end
    subgraph Min Stack
    M1[-2]
    M2[-2]
    M3[-3]
    end
    Note over D3,M3: Pop() removes -3 from both
    Note over D2,M2: Current Min is -2
```

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(1)$ for all operations (`push`, `pop`, `top`, `getMin`).
- **Space Complexity**: $O(N)$ — We store at most $2N$ elements (main stack + auxiliary stack).

---
[View C++ Code](../../01_Data_Structures/Stack/LC_155_Min_Stack.cpp)
