# LC #138: Copy List with Random Pointer (C++ Logic)

> **Pattern Card**: Node Interweaving (Three-Pass Strategy)
> **Goal**: Create a deep copy of a list with complex pointer structures while optimizing for space.

---

## 🎤 The Interview Pitch
"While a deep copy of a linked list can be achieved using a hash map for $O(N)$ space, to truly demonstrate advanced engineering, I solve this in $O(1)$ auxiliary space. The technique involves a 3-pass strategy: first, interweaving copy nodes into the original list; second, mirroring the 'random' pointers; and third, carefully de-coupling the two intertwined lists. This approach is highly memory-efficient and avoids the overhead of a large hash-based structure."

---

## 🏗️ The Artistic Strategy: Interweaving

### Phase 1: Creation and Interleaving
We create a new node `A'` for every node `A` and place it immediately after.
- Original: `A -> B -> C`
- Interleaved: `A -> A' -> B -> B' -> C -> C'`

### Phase 2: Random Pointer Mirroring
The magic happens here. Because `A'` is immediately after `A`, the random pointer for `A'` is simply `A->random->next`.
```cpp
curr->next->random = curr->random->next;
```

### Phase 3: Separation
We surgically split the lists by re-linking the `next` pointers to their skip-one neighbors.

---

## ⚙️ C++ Implementation Analysis

### Memory Safety & Lifetime
In C++, we are creating new nodes using the `new` operator. Since this is a "Deep Copy," it is the caller's responsibility to manage the lifetime of the returned list, while the original list remains untouched.

### Avoid Hash Map Overhead
By using interweaving, we avoid the potential collisions and memory fragmentation associated with large hash maps (like `std::unordered_map<Node*, Node*>`). This is preferred in embedded systems or high-performance game engines where memory locality is critical.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N)$ — We perform three sequential passes over the list.
- **Space Complexity**: $O(1)$ — Excluding the space for the new list, no auxiliary data structures are used.

---
[View C++ Code](../../01_Data_Structures/Linked_List/LC_138_Copy_List_Random_Pointer.cpp)
