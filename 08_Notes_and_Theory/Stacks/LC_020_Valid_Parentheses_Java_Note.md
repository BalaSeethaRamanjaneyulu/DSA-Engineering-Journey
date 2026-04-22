# LC #020: Valid Parentheses (Java Logic)

> **Pattern Card**: LIFO Balancing
> **Goal**: Use Java's collection framework to validate bracket nesting and order.

---

## 🎤 The Interview Pitch
"In Java, the `java.util.Stack` class provides a direct implementation of the push/pop interface needed for balancing symbols. By integrating it with a `HashMap`, we can create a clean, O(1)-lookup mapping between closing and opening brackets. As we iterate through the characters of the string, the stack maintains the order of pending opening brackets, ensuring that the most recently opened one matches the current closing bracket. This ensures linear time complexity and robust handling of nested structures."

---

## 🏗️ The Logic Engine

### 1. The Map Utility
We use a `HashMap<Character, Character>` to store the pairs:
- `')' -> '('`
- `'}' -> '{'`
- `']' -> '['`
This allows us to handle any number of bracket types by simply adding them to the map.

### 2. The Verification Loop
For every character:
- If it's a **Key (Closing)**: Pop from stack and verify against the map's value.
- If it's **Not a Key (Opening)**: Push to stack.

---

## ⚙️ Java Implementation Analysis

### Object Wrappers
Since `Stack` and `HashMap` in Java work with objects, we use `Character` wrappers. While this adds a small amount of memory overhead compared to primitive `char` arrays, it provides a much more flexible and idiomatic implementation.

### Thread Safety
Note that `java.util.Stack` is a legacy class that extends `Vector` and is synchronized. In a highly concurrent production environment, `java.util.Deque` implemented via `ArrayDeque` is often preferred for better performance, but for interview algorithmic code, `Stack` is perfectly acceptable and clarifies intent.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Java Code](../../01_Data_Structures/Stack/LC_020_Valid_Parentheses.java)
