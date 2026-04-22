# LC #020: Valid Parentheses (Python Logic)

> **Pattern Card**: LIFO Balancing
> **Goal**: Leverage Python's dynamic list as a stack for elegant symbol mapping.

---

## 🎤 The Interview Pitch
"Python offers the most concise implementation for bracket balancing due to its dynamic lists, which serve as perfect stacks using `append()` and `pop()`. By creating a truth-mapping with a dictionary, we can perform $O(1)$ lookups for matching pairs. The logic elegantly handles nested structure by ensuring the stack is both non-empty and matching during every closing bracket encounter. If the stack is empty at the end of the scan, the sequence is structurally sound."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Logic** | Stack STL | Stack Class | **List `[]`** |
| **Mapping** | `unordered_map` | `HashMap` | **Dict `{}`** |
| **Truthiness** | `st.empty()` | `stack.isEmpty()` | **`not stack`** |

### Why Python is "Better" for this Problem?
Python's "Truthiness" makes the final validation extremely clean: `return not stack`. Additionally, the ability to use `for char in s:` directly over the string and the simplicity of dict lookups using `if char in mapping:` significantly reduces boilerplate compared to C++ or Java.

---

## 🎨 Logic Visualization (Phase Trace)
Input: `s = "([)]"`

1. `char = '('`: `stack = ['(']`
2. `char = '['`: `stack = ['(', '[']`
3. `char = ')'`: 
   - `top = stack.pop()` -> `'['`
   - `mapping[')'] == '('`
   - **Mismatch**: `'(' != '['` -> **RETURN FALSE**

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Python Code](../../01_Data_Structures/Stack/LC_020_Valid_Parentheses.py)
