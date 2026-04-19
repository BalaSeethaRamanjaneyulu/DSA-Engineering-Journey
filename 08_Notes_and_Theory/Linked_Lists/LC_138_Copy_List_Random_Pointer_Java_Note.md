# LC #138: Copy List with Random Pointer (Java Logic)

> **Pattern Card**: Node Interweaving (Three-Pass Strategy)
> **Goal**: Achieve a deep copy of complex reference structures with $O(1)$ auxiliary space.

---

## 🎤 The Interview Pitch
"While Java's `HashMap<Node, Node>` provides a straightforward $O(N)$ space solution for deep copying lists with random pointers, I demonstrate architectural maturity by implementing the **Node Interweaving** approach. This method avoids the memory overhead and hashing complexity of a map by temporarily interleaving copy nodes inside the original list. It ensures linear time performance while remaining extremely memory-efficient, which is critical for large-scale data processing in Java."

---

## 🏗️ The 3-Phase Logic (Java Perspective)

### Phase 1: Interleaving (Reference Injection)
We insert each copy node directly into the `next` path of its original node.
- `curr.next` points to `copy`
- `copy.next` points to the old `curr.next`

### Phase 2: Random Mapping
Because the copy node is always the `next` neighbor of the original, we can map random pointers without lookup logic:
```java
curr.next.random = (curr.random != null) ? curr.random.next : null;
```

### Phase 3: Surgical Separation
We decouple the two lists by skipping nodes in the `next` chain.

---

## ⚙️ Java Implementation Analysis

### Null Pointer Safety
In Java, we must explicitly check for `null` in the random pointers (`curr.random != null`) before accessing `curr.random.next` to avoid `NullPointerException`.

### Garbage Collection & Immutability
This approach is "safe" because it restores the original list to its exact initial state in Phase 3. This is essential in enterprise systems where the original list might be passed by reference and should not be mutated permanently.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$ — Three linear passes.
- **Space Complexity**: $O(1)$ — No additional data structures (maps/sets) used.

---
[View Java Code](../../01_Data_Structures/Linked_List/LC_138_Copy_List_Random_Pointer.java)
