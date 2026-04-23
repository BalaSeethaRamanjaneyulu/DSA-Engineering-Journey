/**
 * @file LC_739_Daily_Temperatures.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 739: Daily Temperatures
 */

import java.util.Stack;

public class LC_739_Daily_Temperatures {
    /**
     * Calculates the number of days until a warmer temperature for each day.
     * 
     * @param temperatures Array of daily temperatures.
     * @return int[] Array of waiting days.
     */
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>(); // Stores indices

        for (int i = 0; i < n; i++) {
            // While current temperature is warmer than the one at stack's top index
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                int prevIndex = stack.pop();
                result[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }

        return result;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_739_Daily_Temperatures sol = new LC_739_Daily_Temperatures();
        
        int[] temp1 = {73, 74, 75, 71, 69, 72, 76, 73};
        int[] res1 = sol.dailyTemperatures(temp1);
        System.out.print("Test 1: ");
        for (int x : res1) System.out.print(x + " ");
        System.out.println();
    }
}
