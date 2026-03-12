# Problem:  Maximum Subarray
# Platform: LeetCode #053
# Approach: Kadane's Algorithm (Dynamic Programming / Greedy)
# Time:     O(N)  — single pass
# Space:    O(1)  — no extra space
# Link:     https://leetcode.com/problems/maximum-subarray/
#
# Description:
#   Given an integer array nums, find the subarray with the largest sum,
#   and return its sum. Kadane's algorithm keeps a running positive sum.
#   If the running sum goes negative, it resets to 0, because a negative
#   prefix sum will always decrease the sum of any future subarray.

from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        Finds the subarray with the largest sum.
        
        Args:
            nums: List of integers.
            
        Returns:
            int: Maximum subarray sum.
        """
        max_sum = nums[0]
        current_sum = 0
        
        for num in nums:
            if current_sum < 0:
                current_sum = 0
            current_sum += num
            
            if current_sum > max_sum:
                max_sum = current_sum
                
        return max_sum

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Test 1 — Max Subarray Sum: {sol.maxSubArray(nums1)}")
    # Expected: 6

    # Test 2
    nums2 = [1]
    print(f"Test 2 — Max Subarray Sum: {sol.maxSubArray(nums2)}")
    # Expected: 1

    # Test 3
    nums3 = [-5, -1, -3]
    print(f"Test 3 — Max Subarray Sum: {sol.maxSubArray(nums3)}")
    # Expected: -1
