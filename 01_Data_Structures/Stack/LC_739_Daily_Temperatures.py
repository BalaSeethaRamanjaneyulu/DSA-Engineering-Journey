"""
Problem:  Daily Temperatures
Platform: LeetCode #739
Approach: Monotonic Stack (Decreasing)
Efficiency: Time O(N), Space O(N)
"""

from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        """
        Calculates the number of days until a warmer temperature for each day.
        """
        n = len(temperatures)
        res = [0] * n
        stack = [] # Stores indices (i)
        
        for i, t in enumerate(temperatures):
            # While current temp is warmer than the temp at the top index in stack
            while stack and t > temperatures[stack[-1]]:
                prev_i = stack.pop()
                res[prev_i] = i - prev_i
            stack.append(i)
            
        return res

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def test_daily_temps():
    sol = Solution()
    
    # Case 1: Mixed temperatures
    t1 = [73, 74, 75, 71, 69, 72, 76, 73]
    expected1 = [1, 1, 4, 2, 1, 1, 0, 0]
    assert sol.dailyTemperatures(t1) == expected1
    
    # Case 2: Strictly increasing
    t2 = [30, 40, 50, 60]
    expected2 = [1, 1, 1, 0]
    assert sol.dailyTemperatures(t2) == expected2
    
    # Case 3: Strictly decreasing
    t3 = [90, 80, 70]
    expected3 = [0, 0, 0]
    assert sol.dailyTemperatures(t3) == expected3
    
    print("All Python Daily Temperatures test cases passed!")

if __name__ == "__main__":
    test_daily_temps()
