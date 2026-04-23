# LC #150: Evaluate Reverse Polish Notation (Python Logic)

> **Pattern Card**: Postfix Evaluation (LIFO)
> **Goal**: Evaluate RPN expressions while strictly adhering to division truncation rules.

---

## 🎤 The Interview Pitch
"Python's dynamic lists are highly efficient as stacks for RPN evaluation. However, the core engineering challenge in this problem is handling division. Unlike C++ or Java, Python's floor division operator `//` truncates toward negative infinity (e.g., `-6 // 132` becomes `-1`). To satisfy the requirement of truncation toward zero (where `-0.045` becomes `0`), we use `int(a / b)`. This ensures that our stack-based arithmetic engine is numerically accurate across all languages and edge cases."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Logic** | Stack STL | Stack Class | **Dynamic List `[]`** |
| **Division** | `a / b` | `a / b` | **`int(a / b)`** |
| **Membership**| `unordered_set` | `equals()` | **`in {...}`** |

### Why Python is "Better" for this Problem?
Python's set membership syntax (`if token in {"+", "-", "*", "/"}:`) is the most readable among the three languages. Additionally, Python's arbitrary-precision integers mean we don't have to worry about overflow for intermediate multiplication steps, which can be an issue in C++ (requiring `long long`).

---

## 🎨 Logic Visualization (Division Truncation)
In Python:
- `-1 // 10` = `-1` (Floor division)
- `int(-1 / 10)` = `0` (Truncation toward zero) **<- Correct for LC #150**

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Python Code](../../01_Data_Structures/Stack/LC_150_Evaluate_Reverse_Polish_Notation.py)
