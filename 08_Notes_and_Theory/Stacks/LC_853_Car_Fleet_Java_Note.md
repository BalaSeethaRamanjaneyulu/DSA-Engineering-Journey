# LC #853: Car Fleet (Java Logic)

> **Pattern Card**: Array Sorting + Monotonic Stack
> **Goal**: Track fleet collisions using object-oriented sorting and stack manipulation.

---

## 🎤 The Interview Pitch
"In Java, we handle the Car Fleet problem by encapsulating the `position` and `speed` of each car into a custom `Car` object. This allows us to sort the array of cars based on their positions in descending order. As we iterate through these sorted cars, we calculate the time it takes for each to reach the target. Using a `java.util.Stack<Double>`, we compare the current car's arrival time with the fleet ahead of it (the top of the stack). If the current car takes strictly more time, it forms a new fleet, and we push its time onto the stack. If it takes less or equal time, it catches up and becomes part of the fleet ahead, so we do nothing. The number of fleets is simply the size of the stack."

---

## 🏗️ The Engineering Nuance: Object Encapsulation

Java lacks a built-in `Pair` or `Tuple` class in its standard library that is as lightweight as C++'s `std::pair` or Python's tuples. While one could use a 2D array `int[][] cars`, creating a private inner class `Car` is far more readable and idiomatic in enterprise Java.

```java
private class Car {
    int position;
    int speed;
    Car(int p, int s) { position = p; speed = s; }
}
```
Sorting becomes highly readable using a lambda expression:
`Arrays.sort(cars, (a, b) -> Integer.compare(b.position, a.position));`

---

## ⚙️ Time Calculation & Precision
The core logic relies on exact fractional time.
`double time = (double)(target - cars[i].position) / cars[i].speed;`
Casting one of the operands to `double` *before* the division ensures floating-point division. If we did `(target - pos) / speed` first, it would perform integer division and truncate the decimal, leading to incorrect collision logic.

---

## 📐 Complexity Breakdown
- **Time Complexity**: $O(N \log N)$ — Sorting the array of `Car` objects dominates the time complexity. The stack operations are $O(N)$.
- **Space Complexity**: $O(N)$ — The `Car` array and the `Stack<Double>` both require $O(N)$ auxiliary space.

---
[View Java Code](../../01_Data_Structures/Stack/LC_853_Car_Fleet.java)
