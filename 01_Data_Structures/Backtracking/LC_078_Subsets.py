# Problem:  Subsets
# Platform: LeetCode #078
# Approach: Backtracking (Pick & Don't Pick)
# Time:     O(N * 2^N) — Generally 2^N subsets, each copied taking up to O(N)
# Space:    O(N)       — Call stack depth plus path storage
# Link:     https://leetcode.com/problems/subsets/
#
# Description:
#   Given an integer array nums of unique elements, return all possible
#   subsets (the power set). The solution set must not contain duplicate
#   subsets. Return the solution in any order.

from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """
        Generates all possible subsets of the provided array using backtracking.
        
        Args:
            nums: List of unique integers.
            
        Returns:
            List[List[int]]: A 2D list representing the power set.
        """
        result = []
        path = []
        
        def backtrack(index: int):
            # Base Case: processed all elements
            if index == len(nums):
                # Add a copy of the path
                result.append(path[:])
                return
            
            # Choice 1: INCLUDE current element
            path.append(nums[index])
            backtrack(index + 1)
            
            # Choice 2: EXCLUDE current element (Backtracking step)
            path.pop()
            backtrack(index + 1)
            
        backtrack(0)
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [1, 2, 3]
    print("Test 1 — Subsets:")
    print(sol.subsets(nums1))
    print()
    # Expected: [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3], []]

    # Test 2
    nums2 = [0]
    print("Test 2 — Subsets:")
    print(sol.subsets(nums2))
    print()
    # Expected: [[0], []]
