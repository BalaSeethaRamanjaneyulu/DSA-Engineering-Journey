# Problem:  Merge Sorted Array
# Platform: LeetCode #088
# Approach: Three Pointers (Iterate Backwards)
# Time:     O(m + n)  — single pass from the end
# Space:    O(1)  — in-place modification
# Link:     https://leetcode.com/problems/merge-sorted-array/
#
# Description:
#   You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
#   and two integers m and n, representing the number of elements in nums1 and nums2 
#   respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order.
#   The final sorted array should not be returned by the function, but instead be stored 
#   inside the array nums1. To accommodate this, nums1 has a length of m + n.

from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Merges nums2 into nums1 in-place.
        
        Args:
            nums1: List format holding m valid elements with total length m + n.
            m: Number of valid elements in nums1.
            nums2: List to merge.
            n: Number of valid elements in nums2.
        """
        i = m - 1       # Pointer for nums1 valid portion
        j = n - 1       # Pointer for nums2
        k = m + n - 1   # Pointer for write location in nums1
        
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
            
        # If nums2 has remaining elements, place them.
        # If nums1 has remaining elements, they are already at the beginning.
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1_1 = [1, 2, 3, 0, 0, 0]
    nums2_1 = [2, 5, 6]
    sol.merge(nums1_1, 3, nums2_1, 3)
    print(f"Test 1 — Result: {nums1_1}")
    # Expected: [1, 2, 2, 3, 5, 6]

    # Test 2
    nums1_2 = [1]
    nums2_2 = []
    sol.merge(nums1_2, 1, nums2_2, 0)
    print(f"Test 2 — Result: {nums1_2}")
    # Expected: [1]

    # Test 3
    nums1_3 = [0]
    nums2_3 = [1]
    sol.merge(nums1_3, 0, nums2_3, 1)
    print(f"Test 3 — Result: {nums1_3}")
    # Expected: [1]
