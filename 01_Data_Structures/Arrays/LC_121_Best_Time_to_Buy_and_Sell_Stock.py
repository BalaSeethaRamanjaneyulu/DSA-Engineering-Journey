# Problem:  Best Time to Buy and Sell Stock
# Platform: LeetCode #121
# Approach: Greedy / Single-Pass Min-Tracking
# Time:     O(N)  — one pass through the prices array
# Space:    O(1)  — only two variables: min_price and max_profit
# Link:     https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#
# Description:
#   Given an array `prices` where prices[i] is the price of a stock on day i,
#   find the maximum profit you can achieve by buying on one day and selling
#   on a LATER day. Return 0 if no profit is possible.
#
# Key Insight:
#   Track the minimum price seen so far (best buy day).
#   At every step, compute profit = current price - min_price.
#   Update max_profit whenever we see a better profit.
#   This works because: to maximise profit we always want to buy as cheap
#   as possible BEFORE we sell — so we track the running minimum.


from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Finds the maximum profit from a single buy-sell transaction.

        Args:
            prices: List of stock prices indexed by day.

        Returns:
            int: Maximum profit achievable, or 0 if no profit is possible.
        """
        min_price = float('inf')  # cheapest buy day seen so far
        max_profit = 0            # best profit seen so far

        for price in prices:
            if price < min_price:
                min_price = price          # found a cheaper day to buy
            elif price - min_price > max_profit:
                max_profit = price - min_price  # found a better sell day

        return max_profit


# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1: standard profitable case
    prices1 = [7, 1, 5, 3, 6, 4]
    print(f"Test 1 — Max Profit: {sol.maxProfit(prices1)}")
    # Buy on day 2 (price=1), sell on day 5 (price=6) → profit = 5

    # Test 2: prices always decreasing (no profit possible)
    prices2 = [7, 6, 4, 3, 1]
    print(f"Test 2 — Max Profit: {sol.maxProfit(prices2)}")
    # Expected: 0 (never makes sense to sell)

    # Test 3: single element (can't buy and sell)
    prices3 = [5]
    print(f"Test 3 — Max Profit: {sol.maxProfit(prices3)}")
    # Expected: 0

    # Test 4: profit at the very end
    prices4 = [1, 2, 3, 4, 5]
    print(f"Test 4 — Max Profit: {sol.maxProfit(prices4)}")
    # Buy day 1(price=1), sell day 5 (price=5) → profit = 4
