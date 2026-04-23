# LC #739: Daily Temperatures (Java Logic)

> **Pattern Card**: Monotonic Stack (Decreasing)
> **Goal**: Efficiently calculate wait times for warmer temperatures using Java's collection framework.

---

## 🎤 The Interview Pitch
"In Java, implementing the Monotonic Stack pattern for the Daily Temperatures problem involves maintaining a stack of indices. As we iterate through the temperatures array, we maintain a strictly decreasing order of temperatures within the stack. When we encounter a temperature that is strictly higher than the temperature at the index stored at the top of the stack, we have found our 'warmer day'. We pop the index, calculate the difference between the current index and the popped index, and update our result array. This ensures each index is pushed and popped exactly once, providing an optimal $O(N)$ solution."

---

## 🏗️ The Logic Engine: Why Indices?

In Monotonic Stack problems, we almost always store **Indices** rather than **Values**.
1. **Value Access**: We can always get the value using `temperatures[index]`.
2. **Distance Calculation**: The core requirement is "how many days", which is calculated by `currentIndex - poppedIndex`.

---

## ⚙️ Java Implementation Analysis

### Stack Selection
We use `java.util.Stack<Integer>` to manage the indices. Since the problem involves potentially large arrays (up to $10^5$), the overhead of autoboxing `int` to `Integer` is manageable, but in extreme competitive programming scenarios, a primitive `int[]` stack with a pointer would be even faster.

### Initializing Results
Java's primitive `int[]` array is automatically initialized with `0`s. This is convenient because for days that never find a warmer temperature, the required output is `0`, so no extra handling is needed for those indices remaining on the stack at the end.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Java Code](../../01_Data_Structures/Stack/LC_739_Daily_Temperatures.java)
