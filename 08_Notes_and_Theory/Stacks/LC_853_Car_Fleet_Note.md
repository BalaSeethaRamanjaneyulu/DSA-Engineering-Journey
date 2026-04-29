# LC #853: Car Fleet (C++ Logic)

> **Pattern Card**: Array Sorting + Monotonic Stack
> **Goal**: Determine fleet formation by analyzing arrival times based on sorted positions.

---

## 🎤 The Interview Pitch
"To determine how many car fleets will arrive at the destination, we must analyze the cars starting from the one closest to the target. By pairing each car's position and speed, we can sort them in descending order of position. We then calculate the arrival time for each car using `Time = (Target - Position) / Speed`. Using a stack, we iterate through the sorted cars. If a car's calculated time is less than or equal to the time of the fleet in front of it (top of the stack), it will catch up and form a fleet, so we don't push it. If it takes strictly more time, it cannot catch up, meaning it forms a new fleet, so we push its time onto the stack. The final size of the stack represents the number of distinct fleets."

---

## 🔍 Language-Specific Implementation (Comparative Analysis)

| Feature | C++ | Java | Python |
| :--- | :--- | :--- | :--- |
| **Data Binding**| `std::pair<int, int>` | Custom `class Car` | **Tuples `(p, s)`** |
| **Sorting** | `std::sort` | `Arrays.sort` | **`sorted()`** |
| **Division** | `(double)d / s` | `(double)d / s` | **`d / s` (float division)** |

### Why C++ for this Design?
C++ provides `std::pair`, which is highly efficient for binding two related values without the overhead of declaring a new class. `std::sort` can natively sort a `vector<pair>` based on the first element (position), making the setup code concise and performant. Casting to `double` is crucial because fractional times dictate fleet collisions.

---

## 🎨 Logic Visualization (Mermaid)
Target: 12. Cars: `[(10, 2), (8, 4), (0, 1), (5, 1), (3, 3)]`
Sorted by Position: `(10,2), (8,4), (5,1), (3,3), (0,1)`

```mermaid
graph TD
    C1[Car at 10: Time = 1] --> S1[Stack: 1]
    C2[Car at 8: Time = 1] --> S2[1 <= 1: Catches up, Stack: 1]
    C3[Car at 5: Time = 7] --> S3[7 > 1: New Fleet, Stack: 1, 7]
    C4[Car at 3: Time = 3] --> S4[3 <= 7: Catches up, Stack: 1, 7]
    C5[Car at 0: Time = 12] --> S5[12 > 7: New Fleet, Stack: 1, 7, 12]
    Note over S5: Total Fleets = 3
```

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N \log N)$ — Dominated by the sorting step. The stack processing is $O(N)$.
- **Space Complexity**: $O(N)$ — We require $O(N)$ space to store the pairs and $O(N)$ for the stack.

---
[View C++ Code](../../01_Data_Structures/Stack/LC_853_Car_Fleet.cpp)
