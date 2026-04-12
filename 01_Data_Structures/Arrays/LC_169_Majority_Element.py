# Problem:  Majority Element
# Platform: LeetCode #169
# Approach: Boyer-Moore Voting Algorithm
# Time:     O(N)  — Single pass
# Space:    O(1)  — No extra space
# Link:     https://leetcode.com/problems/majority-element/
#
# Description:
#   Given an array nums of size n, return the majority element.
#   The majority element is the element that appears more than ⌊n / 2⌋ times.
#   You may assume that the majority element always exists in the array.

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        """
        Finds the majority element using Boyer-Moore Voting.
        
        Args:
            nums: List of integers.
            
        Returns:
            int: The majority element.
        """
        candidate = 0
        count = 0
        
        for num in nums:
            if count == 0:
                candidate = num
            if num == candidate:
                count += 1
            else:
                count -= 1
                
        return candidate

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [3, 2, 3]
    print(f"Test 1 — Majority Element: {sol.majorityElement(nums1)}")
    # Expected: 3

    # Test 2
    nums2 = [2, 2, 1, 1, 1, 2, 2]
    print(f"Test 2 — Majority Element: {sol.majorityElement(nums2)}")
    # Expected: 2

    # Test 3
    nums3 = [5]
    print(f"Test 3 — Majority Element: {sol.majorityElement(nums3)}")
    # Expected: 5
