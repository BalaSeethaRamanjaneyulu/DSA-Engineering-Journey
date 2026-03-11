# Problem:  Remove Duplicates from Sorted Array
# Platform: LeetCode #026
# Approach: Two Pointers
# Time:     O(N)  — single pass
# Space:    O(1)  — in-place modification
# Link:     https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#
# Description:
#   Given an integer array nums sorted in non-decreasing order, remove
#   the duplicates in-place such that each unique element appears only once.
#   Return k after placing the final result in the first k slots of nums.

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        Removes duplicates from a sorted array in-place.
        
        Args:
            nums: List of integers sorted in non-decreasing order.
            
        Returns:
            int: Number of unique elements.
        """
        if not nums:
            return 0
        
        i = 0 # pointer for the last unique element
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        
        return i + 1

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [1, 1, 2]
    k1 = sol.removeDuplicates(nums1)
    print(f"Test 1 — k: {k1}, result: {nums1[:k1]}")
    # Expected: 2, [1, 2]

    # Test 2
    nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k2 = sol.removeDuplicates(nums2)
    print(f"Test 2 — k: {k2}, result: {nums2[:k2]}")
    # Expected: 5, [0, 1, 2, 3, 4]
