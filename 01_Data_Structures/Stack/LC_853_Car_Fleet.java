/**
 * @file LC_853_Car_Fleet.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 853: Car Fleet
 */

import java.util.Arrays;
import java.util.Stack;

public class LC_853_Car_Fleet {
    /**
     * Inner class to represent a Car's position and speed.
     */
    private class Car {
        int position;
        int speed;
        Car(int p, int s) {
            position = p;
            speed = s;
        }
    }

    /**
     * Calculates the number of car fleets.
     * 
     * @param target The destination distance.
     * @param position Array of car starting positions.
     * @param speed Array of car speeds.
     * @return int Number of fleets.
     */
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        if (n == 0) return 0;

        Car[] cars = new Car[n];
        for (int i = 0; i < n; i++) {
            cars[i] = new Car(position[i], speed[i]);
        }

        // Sort cars by position descending
        Arrays.sort(cars, (a, b) -> Integer.compare(b.position, a.position));

        Stack<Double> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].position) / cars[i].speed;

            // If the current car takes MORE time than the fleet in front of it,
            // it cannot catch up and forms a new fleet.
            if (stack.isEmpty() || time > stack.peek()) {
                stack.push(time);
            }
        }

        return stack.size();
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_853_Car_Fleet sol = new LC_853_Car_Fleet();
        
        int[] pos1 = {10, 8, 0, 5, 3};
        int[] speed1 = {2, 4, 1, 1, 3};
        System.out.println("Test 1: " + sol.carFleet(12, pos1, speed1) + " (Expected: 3)");

        int[] pos2 = {3};
        int[] speed2 = {3};
        System.out.println("Test 2: " + sol.carFleet(10, pos2, speed2) + " (Expected: 1)");
    }
}
