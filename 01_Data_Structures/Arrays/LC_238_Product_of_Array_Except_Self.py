# Problem:  Product of Array Except Self
# Platform: LeetCode #238
# Approach: Prefix and Suffix Products (Left & Right Passes)
# Time:     O(N)  — two passes over the array
# Space:    O(1)  — excluding the output array
# Link:     https://leetcode.com/problems/product-of-array-except-self/
#
# Description:
#   Given an integer array nums, return an array answer such that answer[i] 
#   is equal to the product of all the elements of nums except nums[i].
#   You must write an algorithm that runs in O(n) time and without using 
#   the division operation.

from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Computes the product of array except self without division.
        
        Args:
            nums: List of integers.
            
        Returns:
            List[int]: Product array result.
        """
        n = len(nums)
        result = [1] * n
        
        # Pass 1: Compute left prefix products
        left_product = 1
        for i in range(n):
            result[i] = left_product
            left_product *= nums[i]
            
        # Pass 2: Compute right suffix products and multiply with left product
        right_product = 1
        for i in range(n - 1, -1, -1):
            result[i] *= right_product
            right_product *= nums[i]
            
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [1, 2, 3, 4]
    print(f"Test 1 — Result: {sol.productExceptSelf(nums1)}")
    # Expected: [24, 12, 8, 6]

    # Test 2
    nums2 = [-1, 1, 0, -3, 3]
    print(f"Test 2 — Result: {sol.productExceptSelf(nums2)}")
    # Expected: [0, 0, 9, 0, 0]
