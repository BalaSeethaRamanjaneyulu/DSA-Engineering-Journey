# LC #155: Min Stack (Java Logic)

> **Pattern Card**: Auxiliary State Persistence (Two-Stack Method)
> **Goal**: Implement a constant-time minimum retrieval stack while handling Java object comparison nuances.

---

## 🎤 The Interview Pitch
"In Java, implementing a `MinStack` requires careful coordination between the primary data `Stack` and an auxiliary `minStack`. The key technical challenge in Java is ensuring that our `pop()` logic correctly identifies when a minimum is being removed. Since `java.util.Stack` stores `Integer` objects, we must use `.equals()` rather than `==` for comparisons to handle values outside the small integer cache. This approach guarantees $O(1)$ performance for all operations while maintaining strong structural integrity."

---

## 🏗️ The Engineering Nuance: Integer Comparison

In Java's `Integer` class, values between -128 and 127 are cached. Using `==` on larger values compares memory addresses, not the actual values.
```java
// WRONG for large values (e.g., 200)
if (stack.peek() == minStack.peek()) 

// CORRECT
if (stack.peek().equals(minStack.peek()))
```
Our implementation strictly adheres to this standard to ensure production-grade reliability.

---

## ⚙️ Java Implementation Analysis

### Stack Choice
We choose `java.util.Stack` for its explicit naming and historical context in interview coding. While `ArrayDeque` is technically faster for stack operations (as it is non-synchronized), `Stack` is very common in whiteboarding scenarios to clearly communicate the LIFO intent.

### Redundancy Optimization
Note that we only push to the `minStack` if the new value is *less than or equal* to the current minimum. This handles duplicate minimums correctly.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(1)$
- **Space Complexity**: $O(N)$

---
[View Java Code](../../01_Data_Structures/Stack/LC_155_Min_Stack.java)
