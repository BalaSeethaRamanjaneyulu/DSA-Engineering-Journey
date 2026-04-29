# LC #084: Largest Rectangle in Histogram (Python Logic)

> **Pattern Card**: Monotonic Stack (Strictly Increasing)
> **Goal**: Evaluate maximal rectangular area dynamically using pythonic array modification techniques.

---

## 🎤 The Interview Pitch
"In Python, the Largest Rectangle problem is optimally solved using a Monotonic Stack of indices. To cleanly process the stack at the end of the histogram iteration, we can employ a pythonic trick: temporarily appending a `0` to the end of the `heights` array. Because `0` is shorter than any valid bar, it forces our `while` loop to pop and evaluate every remaining bar in the stack. We calculate the area dynamically for each popped bar, using its height and the distance to the new top of the stack as its width. Once the iteration completes, we pop the `0` from the array to leave the input unmodified, maintaining clean functional boundaries."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Logic** | Stack STL | Stack Class | **List `[]`** |
| **Phantom Bar**| Loop index limit (`i <= n`) | Loop index limit (`i <= n`) | **`heights.append(0)`** |
| **Traversal** | Standard `for` | Standard `for` | **`enumerate()`** |

### Why Python is "Better" for this Problem?
In C++ and Java, modifying the input array parameter is generally frowned upon or less efficient due to fixed sizes. However, Python's dynamic lists make `append()` and `pop()` $O(1)$ operations at the tail. By writing `heights.append(0)`, we avoid the ternary conditional logic inside the loop entirely, making the loop body significantly cleaner.

---

## 🎨 Logic Visualization (Area Calculation)
When evaluating the bar at index `pop_idx`, the width of the rectangle is bounded by:
- **Right Boundary**: `i` (the current index that triggered the pop).
- **Left Boundary**: `stack[-1]` (the index of the next lowest bar to the left).
- **Formula**: `width = i - stack[-1] - 1`

If the stack is empty after popping, it means this bar is the lowest encountered so far, so it extends all the way to index `0`. Thus, `width = i`.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Python Code](../../01_Data_Structures/Stack/LC_084_Largest_Rectangle_in_Histogram.py)
