# LC #150: Evaluate Reverse Polish Notation (Java Logic)

> **Pattern Card**: Postfix Evaluation (LIFO)
> **Goal**: Evaluate arithmetic expressions in a stack-oriented manner using Java collections.

---

## 🎤 The Interview Pitch
"In Java, evaluating RPN expressions involves leveraging the `java.util.Stack` class to store operand integers. As we iterate through the tokens, we perform a constant-time check to distinguish between operands and operators. When an operator is detected, we pop the top two integers (the second pop being the left operand) and apply the arithmetic operation using a clean `switch` expression. Java's default integer division behavior matches the problem's truncation-toward-zero requirement, making the implementation both robust and idiomatic."

---

## 🏗️ The Logic Engine: Switch vs. If-Else

In Java, using a `switch` statement for operator handling is more readable and efficient than a series of `if-else` blocks, especially when dealing with string tokens.
```java
switch (token) {
    case "+": stack.push(a + b); break;
    case "-": stack.push(a - b); break;
    // ...
}
```

### Order of Operands
One critical detail in RPN is the order of subtraction and division. Since the stack is LIFO, the first element popped is the **Right Operand**, and the second element popped is the **Left Operand**.
- Correct: `stack.push(a / b)` where `a` was the 2nd pop and `b` was the 1st pop.

---

## ⚙️ Java Implementation Analysis

### Integer Parsing
We use `Integer.parseInt(token)` to convert strings to primitive integers. Since we are storing them in a `Stack<Integer>`, they are autoboxed into `Integer` objects. For massive inputs, using a primitive array as a manual stack could slightly improve performance by avoiding object allocation, but `Stack<Integer>` is the standard expectation in a coding interview.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$
- **Space Complexity**: $O(N)$

---
[View Java Code](../../01_Data_Structures/Stack/LC_150_Evaluate_Reverse_Polish_Notation.java)
