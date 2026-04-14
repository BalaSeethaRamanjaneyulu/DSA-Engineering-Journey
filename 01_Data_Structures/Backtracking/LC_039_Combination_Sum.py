# Problem:  Combination Sum
# Platform: LeetCode #039
# Approach: Backtracking (Pick or Skip)
# Time:     O(2^t * k) where t is target/min_candidate
# Space:    O(target) due to recursive depth
# Link:     https://leetcode.com/problems/combination-sum/
#
# Description:
#   Given an array of distinct integers candidates and a target integer target, 
#   return a list of all unique combinations of candidates where the chosen 
#   numbers sum to target. The same number may be chosen from candidates an 
#   unlimited number of times.

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        Finds all unique combinations that sum up to target.
        
        Args:
            candidates: List of distinct integers.
            target: The target sum to reach.
            
        Returns:
            List[List[int]]: A list of all unique matching combinations.
        """
        result = []
        
        def backtrack(index: int, target: int, path: List[int]):
            # Base Case: Success
            if target == 0:
                result.append(path[:])
                return
            
            # Base Case: Failure
            if index == len(candidates) or target < 0:
                return
            
            # Choice 1: PICK the element at index. 
            # (Stay at current index for potential reuse)
            path.append(candidates[index])
            backtrack(index, target - candidates[index], path)
            # Backtrack
            path.pop()
            
            # Choice 2: SKIP the current index and move to next
            backtrack(index + 1, target, path)
            
        backtrack(0, target, [])
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    c1 = [2, 3, 6, 7]
    t1 = 7
    print(f"Test 1 — Result: {sol.combinationSum(c1, t1)}")
    # Expected: [[2, 2, 3], [7]]
