"""
Problem:  Largest Rectangle in Histogram
Platform: LeetCode #084
Approach: Monotonic Stack (Increasing)
Efficiency: Time O(N), Space O(N)
"""

from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        Finds the maximum rectangular area possible in the given histogram.
        """
        max_area = 0
        stack = [] # Stores indices
        
        # Append 0 to the heights array to flush the stack at the end
        heights.append(0)
        
        for i, h in enumerate(heights):
            # If current height is less than the stack's top height, we found the right boundary
            while stack and h < heights[stack[-1]]:
                height = heights[stack.pop()]
                # If stack is empty, width is i. Otherwise, i - top_index - 1
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            
            stack.append(i)
            
        # Clean up the modified array (good practice)
        heights.pop()
        
        return max_area

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def test_largest_rectangle():
    sol = Solution()
    
    # Case 1: Standard mountain shape
    assert sol.largestRectangleArea([2, 1, 5, 6, 2, 3]) == 10
    
    # Case 2: Strictly increasing
    assert sol.largestRectangleArea([2, 4]) == 4
    
    # Case 3: Flat
    assert sol.largestRectangleArea([2, 2, 2]) == 6
    
    # Case 4: Single bar
    assert sol.largestRectangleArea([5]) == 5
    
    print("All Python Largest Rectangle in Histogram test cases passed!")

if __name__ == "__main__":
    test_largest_rectangle()
