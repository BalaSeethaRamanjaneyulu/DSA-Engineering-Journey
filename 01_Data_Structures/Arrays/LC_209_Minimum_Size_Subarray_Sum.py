# Problem:  Minimum Size Subarray Sum
# Platform: LeetCode #209
# Approach: Sliding Window (Two Pointers)
# Time:     O(N)  — Each element is processed at most twice (added and removed)
# Space:    O(1)  — No extra space
# Link:     https://leetcode.com/problems/minimum-size-subarray-sum/
#
# Description:
#   Given an array of positive integers nums and a positive integer target, 
#   return the minimal length of a contiguous subarray of which the sum is 
#   greater than or equal to target. If there is no such subarray, return 0.

from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        """
        Finds the minimum length of a subarray whose sum is >= target.
        
        Args:
            target: The target sum.
            nums: List of positive integers.
            
        Returns:
            int: Minimal length of the subarray, or 0 if none found.
        """
        n = len(nums)
        min_len = float('inf')
        
        left = 0
        current_sum = 0
        
        for right in range(n):
            current_sum += nums[right]
            
            # Shrink the window while condition is met
            while current_sum >= target:
                min_len = min(min_len, right - left + 1)
                current_sum -= nums[left]
                left += 1
                
        return min_len if min_len != float('inf') else 0

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [2, 3, 1, 2, 4, 3]
    target1 = 7
    print(f"Test 1 — Minimal Length: {sol.minSubArrayLen(target1, nums1)}")
    # Expected: 2

    # Test 2
    nums2 = [1, 4, 4]
    target2 = 4
    print(f"Test 2 — Minimal Length: {sol.minSubArrayLen(target2, nums2)}")
    # Expected: 1

    # Test 3
    nums3 = [1, 1, 1, 1, 1, 1, 1, 1]
    target3 = 11
    print(f"Test 3 — Minimal Length: {sol.minSubArrayLen(target3, nums3)}")
    # Expected: 0
