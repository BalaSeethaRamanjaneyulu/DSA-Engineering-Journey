/**
 * @file LC_121_Best_Time_to_Buy_and_Sell_Stock.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 121: Best Time to Buy and Sell Stock
 *
 *        Problem: Given an array prices where prices[i] is the price of a stock
 *        on
 *        day i, find the maximum profit from a single buy-sell transaction.
 *        Return 0 if no profit is possible.
 *
 *        Platform: LeetCode #121
 *        Approach: Greedy / Single-Pass Min-Tracking
 *        Time: O(N) — one pass through the array
 *        Space: O(1) — only two extra variables
 *        Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

public class LC_121_Best_Time_to_Buy_and_Sell_Stock {

    /**
     * Finds the maximum profit from a single buy-sell transaction.
     *
     * <p>
     * Tracks the minimum price seen so far (best buy day). At every step,
     * computes profit = current_price - minPrice and updates maxProfit
     * whenever a better result is found.
     * </p>
     *
     * @param prices Array of stock prices indexed by day.
     * @return int Maximum profit achievable, or 0 if no profit is possible.
     */
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE; // cheapest buy day seen so far
        int maxProfit = 0; // best profit seen so far

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // found a cheaper day to buy
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice; // found a better sell day
            }
        }

        return maxProfit;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_121_Best_Time_to_Buy_and_Sell_Stock sol = new LC_121_Best_Time_to_Buy_and_Sell_Stock();

        // Test 1: standard profitable case
        int[] prices1 = { 7, 1, 5, 3, 6, 4 };
        System.out.println("Test 1 — Max Profit: " + sol.maxProfit(prices1));
        // Buy day 2 (price=1), sell day 5 (price=6) → profit = 5

        // Test 2: prices always decreasing (no profit possible)
        int[] prices2 = { 7, 6, 4, 3, 1 };
        System.out.println("Test 2 — Max Profit: " + sol.maxProfit(prices2));
        // Expected: 0

        // Test 3: single element (can't buy and sell)
        int[] prices3 = { 5 };
        System.out.println("Test 3 — Max Profit: " + sol.maxProfit(prices3));
        // Expected: 0

        // Test 4: profit at the very end
        int[] prices4 = { 1, 2, 3, 4, 5 };
        System.out.println("Test 4 — Max Profit: " + sol.maxProfit(prices4));
        // Buy day 1 (price=1), sell day 5 (price=5) → profit = 4
    }
}
