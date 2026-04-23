# LC #739: Daily Temperatures (Python Logic)

> **Pattern Card**: Monotonic Stack (Decreasing)
> **Goal**: Find the first greater element to the right using Python's list-based stack.

---

## 🎤 The Interview Pitch
"In Python, the Monotonic Stack pattern is implemented with exceptional clarity using the `enumerate()` function and a dynamic list. By storing indices in a strictly decreasing order of their corresponding temperatures, we can process each day in amortized $O(1)$ time. When a warmer temperature appears, we 'clear' all pending days from the stack that are colder than the current one. This 'clearance' logic ensures that every element enters and exits the stack exactly once, making the overall algorithm $O(N)$ despite the nested `while` loop."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Logic** | `std::stack` | `java.util.Stack` | **List `[]`** |
| **Traversal**| `for` loop | `for` loop | **`enumerate()`** |
| **Indexing** | `st.top()` | `stack.peek()` | **`stack[-1]`** |

### Why Python is "Better" for this Problem?
Python's `enumerate(temperatures)` provides both the index and the value in a single, readable line, avoiding the manual indexing seen in C++ and Java. Furthermore, the expression `stack[-1]` for peeking is cleaner than method calls, allowing the logic of the Monotonic Stack to stand out without syntactic noise.

---

## 🎨 Logic Visualization (Amortized Analysis)
Why is it $O(N)$ even with a `while` loop?
- Imagine a strictly decreasing sequence followed by one massive value.
- The `while` loop will pop all $N-1$ elements in one go.
- Total operations: $N$ pushes + $N$ pops = $2N$ operations total.
- Complexity: $O(2N) \approx O(N)$.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Python Code](../../01_Data_Structures/Stack/LC_739_Daily_Temperatures.py)
