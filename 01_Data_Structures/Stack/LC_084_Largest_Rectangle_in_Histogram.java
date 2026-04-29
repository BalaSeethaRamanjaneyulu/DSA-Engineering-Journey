/**
 * @file LC_084_Largest_Rectangle_in_Histogram.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 084: Largest Rectangle in Histogram
 */

import java.util.Stack;

public class LC_084_Largest_Rectangle_in_Histogram {
    /**
     * Finds the maximum rectangular area in a histogram.
     * 
     * @param heights Array of histogram bar heights.
     * @return int Maximum area.
     */
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!stack.isEmpty() && currentHeight < heights[stack.peek()]) {
                int h = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, h * width);
            }
            
            stack.push(i);
        }

        return maxArea;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_084_Largest_Rectangle_in_Histogram sol = new LC_084_Largest_Rectangle_in_Histogram();
        
        int[] heights1 = {2, 1, 5, 6, 2, 3};
        System.out.println("Test 1: " + sol.largestRectangleArea(heights1) + " (Expected: 10)");

        int[] heights2 = {2, 4};
        System.out.println("Test 2: " + sol.largestRectangleArea(heights2) + " (Expected: 4)");
    }
}
