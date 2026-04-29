# LC #853: Car Fleet (Python Logic)

> **Pattern Card**: Array Sorting + Monotonic Stack
> **Goal**: Evaluate fleet groupings using dynamic lists and pythonic sorting capabilities.

---

## 🎤 The Interview Pitch
"In Python, the 'Car Fleet' problem elegantly demonstrates the power of the `zip` function. Instead of creating custom classes or multi-dimensional arrays, we can instantly pair up positions and speeds using `zip(position, speed)`. Sorting this combined iterable in reverse order automatically aligns the cars starting from the one closest to the target. From there, computing the collision logic is simple: we calculate `time = (target - p) / s` and push it to our list-based stack. If the stack is empty, or if the current car's time is strictly greater than the top of the stack (meaning it forms a new fleet), we push it. Otherwise, it catches up and merges into the existing fleet."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Data Binding**| `std::pair` | `class Car` | **`zip()`** |
| **Sorting** | `std::sort(rbegin, rend)` | `Arrays.sort` | **`sorted(..., reverse=True)`**|
| **Stack DS** | `std::stack` | `java.util.Stack`| **Dynamic List `[]`** |

### Why Python is "Better" for this Problem?
Python's standard library is incredibly expressive here. The single line `cars = sorted(zip(position, speed), reverse=True)` completely replaces the boilerplate needed in C++ and Java. Furthermore, Python's standard division `/` always returns a float, so there is no need for explicit casting like `(double)` to preserve the fractional precision necessary for accurate collision tracking.

---

## 🎨 Logic Visualization (Fleet Merging)
Consider the times of cars sorted by closest position to target:
Times: `[1.0, 1.0, 7.0, 3.0, 12.0]`

1. Stack: `[1.0]`
2. Next is `1.0`. `1.0 <= 1.0` -> Merges. Stack: `[1.0]`
3. Next is `7.0`. `7.0 > 1.0` -> New Fleet. Stack: `[1.0, 7.0]`
4. Next is `3.0`. `3.0 <= 7.0` -> Merges. Stack: `[1.0, 7.0]`
5. Next is `12.0`. `12.0 > 7.0` -> New Fleet. Stack: `[1.0, 7.0, 12.0]`

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N \log N)$ — Dominated by the `sorted()` operation.
- **Space Complexity**: $O(N)$ — To store the zipped pairs and the stack.

---
[View Python Code](../../01_Data_Structures/Stack/LC_853_Car_Fleet.py)
