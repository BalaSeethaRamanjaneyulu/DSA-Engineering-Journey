# ⏪ Backtracking Concepts & Patterns

> "Backtracking is an algorithmic technique that considers searching in every possible combination in order to solve a computational problem."

---

## 🏗️ Core Backtracking Template

Every backtracking problem follows a similar logical structure:

```cpp
void backtrack(state, result, path) {
    if (is_goal(state)) {
        result.add(path);
        return;
    }

    for (choice : available_choices) {
        if (is_valid(choice)) {
            // 1. Choose (Make move)
            make_move(state, choice);
            path.add(choice);

            // 2. Explore (Recurse)
            backtrack(state, result, path);

            // 3. Un-choose (Backtrack/Undo move)
            undo_move(state, choice);
            path.pop();
        }
    }
}
```

---

## 📋 Problem Set & Progress

| Problem | Difficulty | Key Pattern | Solutions |
| :--- | :--- | :--- | :--- |
| **LC #078: Subsets** | Medium | Power Set (Include/Exclude) | [C++](LC_078_Subsets.cpp), [Java](LC_078_Subsets.java), [Python](LC_078_Subsets.py) |
| **LC #046: Permutations** | Medium | State Swapping | [C++](LC_046_Permutations.cpp), [Java](LC_046_Permutations.java), [Python](LC_046_Permutations.py) |
| **LC #039: Combination Sum** | Medium | Pick/Skip (Infinite Reuse) | [C++](LC_039_Combination_Sum.cpp), [Java](LC_039_Combination_Sum.java), [Python](LC_039_Combination_Sum.py) |
| **LC #040: Combination Sum II**| Medium | Sorting + Duplicate Skipping | [C++](LC_040_Combination_Sum_II.cpp), [Java](LC_040_Combination_Sum_II.java), [Python](LC_040_Combination_Sum_II.py) |
| **LC #079: Word Search** | Medium | 2D Grid DFS | [C++](LC_079_Word_Search.cpp), [Java](LC_079_Word_Search.java), [Python](LC_079_Word_Search.py) |
| **LC #051: N-Queens** | Hard | Constraint Satisfaction | [C++](LC_051_N_Queens.cpp), [Java](LC_051_N_Queens.java), [Python](LC_051_N_Queens.py) |
| **LC #131: Palindrome Partitioning**| Medium | Partitional Backtracking | [C++](LC_131_Palindrome_Partitioning.cpp), [Java](LC_131_Palindrome_Partitioning.java), [Python](LC_131_Palindrome_Partitioning.py) |

---

## 🧮 Complexity Cheat Sheet

*   **Subsets**: $O(N \cdot 2^N)$
*   **Permutations**: $O(N \cdot N!)$
*   **Combinations**: $O(k \cdot \binom{n}{k})$
*   **Grid Search (Word Search)**: $O(M \cdot N \cdot 3^L)$

---

## 💡 Key Takeaways

1.  **State Management**: Always ensure you restore the state after a recursive call.
2.  **Pruning**: Identify conditions early to stop exploring invalid branches (e.g., if sum > target).
3.  **Duplicates**: Sorting is your best friend when you need to avoid duplicate combinations.
4.  **Grid DFS**: Use a visited marking (or char swap `#`) to handle state effectively.

---

> *"The art of backtracking is knowing when to stop looking."* 🚀
