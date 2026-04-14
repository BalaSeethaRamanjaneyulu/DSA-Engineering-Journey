# Problem:  Permutations
# Platform: LeetCode #046
# Approach: Backtracking (State Modification)
# Time:     O(N * N!) — There are N! permutations, each takes O(N) to append
# Space:    O(N)      — Due to recursive call stack depth
# Link:     https://leetcode.com/problems/permutations/
#
# Description:
#   Given an array nums of distinct integers, return all the possible 
#   permutations. You can return the answer in any order.

from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        """
        Generates permutations using an in-place swapping element approach.
        
        Args:
            nums: List of distinct integers.
            
        Returns:
            List[List[int]]: A 2D list containing all permutations.
        """
        result = []
        n = len(nums)
        
        def backtrack(start: int = 0):
            # Base Case: all positions are fixed
            if start == n:
                result.append(nums[:])
                return
            
            # Go through elements we haven't fixed yet
            for i in range(start, n):
                # Choose: Swap to put nums[i] at the 'start' position
                nums[start], nums[i] = nums[i], nums[start]
                
                # Explore: process the next positions
                backtrack(start + 1)
                
                # Un-choose: Undo swap (backtrack)
                nums[start], nums[i] = nums[i], nums[start]
                
        backtrack()
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    nums1 = [1, 2, 3]
    print("Test 1 — Permutations:")
    print(sol.permute(nums1))
    print()
    # Expected size: 6

    # Test 2
    nums2 = [0, 1]
    print("Test 2 — Permutations:")
    print(sol.permute(nums2))
    print()
    # Expected size: 2

    # Test 3
    nums3 = [1]
    print("Test 3 — Permutations:")
    print(sol.permute(nums3))
    print()
