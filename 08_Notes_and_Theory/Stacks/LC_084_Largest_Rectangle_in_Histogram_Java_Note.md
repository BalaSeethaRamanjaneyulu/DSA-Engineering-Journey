# LC #084: Largest Rectangle in Histogram (Java Logic)

> **Pattern Card**: Monotonic Stack (Strictly Increasing)
> **Goal**: Evaluate maximal rectangular area in linear time by dynamically collapsing invalid bounds.

---

## 🎤 The Interview Pitch
"In Java, we can solve the Largest Rectangle in Histogram problem by maintaining a `Stack<Integer>` of indices. The stack keeps track of indices where the heights are strictly increasing. This guarantees that for any bar at the top of the stack, the bar immediately below it is its left boundary, and the current bar we are evaluating (if it's shorter) is its right boundary. When we encounter a shorter bar, we pop the top of the stack. We calculate the area using the popped height, and the width is derived by subtracting the new top-of-stack index from the current index. This elegantly collapses the histogram in a single $O(N)$ pass without needing complex Look-Ahead logic."

---

## 🏗️ The Engineering Nuance: The "Phantom" Bar

A common issue in Monotonic Stack problems is what to do with the elements left in the stack after the main loop finishes.
Instead of writing a second `while(!stack.isEmpty())` loop, we can cleverly extend our loop to `n` (inclusive) and simulate a bar of height `0` at index `n`:
```java
int currentHeight = (i == n) ? 0 : heights[i];
```
Because `0` is guaranteed to be less than or equal to any valid height in the histogram, it forces the `while` loop to pop and process every remaining bar in the stack. This keeps the code incredibly DRY (Don't Repeat Yourself).

---

## ⚙️ Java Implementation Analysis
- **`Stack<Integer>` vs Primitive Arrays**: While a `java.util.Stack` involves autoboxing (which adds memory overhead), it is universally accepted in interviews for clarity. If absolute performance is required, one might implement a manual stack using `int[] stack = new int[n];` and an integer pointer `top = -1`.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Java Code](../../01_Data_Structures/Stack/LC_084_Largest_Rectangle_in_Histogram.java)
