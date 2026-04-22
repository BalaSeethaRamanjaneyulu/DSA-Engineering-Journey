# LC #155: Min Stack (Python Logic)

> **Pattern Card**: Tuple-Based State Binding
> **Goal**: Design a constant-time minimum retrieval stack using Python's flexible list structure.

---

## 🎤 The Interview Pitch
"In Python, the most idiomatic and memory-efficient way to implement a `MinStack` is to store every element as a tuple of `(value, current_min)`. By binding the minimum value at the time of entry to the element itself, we eliminate the need for a second auxiliary stack and simplify our `pop()` logic. Every entry in the stack becomes a 'snapshot' of the state, ensuring that `getMin()` always returns the correct value in $O(1)$ time regardless of which elements have been removed."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Logic** | Two Stacks | Two Stacks | **Single Stack (Tuples)** |
| **Encapsulation**| `std::stack` | `java.util.Stack`| **Dynamic List `[]`** |
| **Cleanliness** | Explicit | Robust | **Minimalist** |

### Why Python is "Better" for this Design?
Python's native support for tuples and dynamic lists makes the "State Binding" approach incredibly clean. We don't have to worry about coordinating two different collection objects or managing complex pointer logic. The expression `self.stack[-1][1]` is a concise way to access the metadata (current minimum) without overhead.

---

## 🎨 Logic Visualization (Tuple Snapshots)
Stack Trace for `Push(-2), Push(0), Push(-3)`:

1. `stack = [ (-2, -2) ]`  (Min is -2)
2. `stack = [ (-2, -2), (0, -2) ]` (Min is still -2)
3. `stack = [ (-2, -2), (0, -2), (-3, -3) ]` (New Min is -3)

When we `pop()`, the snapshot at index 1 correctly restores the minimum to `-2`.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(1)$
- **Space Complexity**: $O(N)$

---
[View Python Code](../../01_Data_Structures/Stack/LC_155_Min_Stack.py)
