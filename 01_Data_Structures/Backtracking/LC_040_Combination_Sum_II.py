# Problem:  Combination Sum II
# Platform: LeetCode #040
# Approach: Backtracking (Sort + Duplicate Skipping)
# Time:     O(2^N * N)
# Space:    O(N)
# Link:     https://leetcode.com/problems/combination-sum-ii/
#
# Description:
#   Given a collection of candidate numbers (candidates) and a target number 
#   (target), find all unique combinations in candidates where the candidate 
#   numbers sum to target. Each number in candidates may only be used once 
#   in the combination. Duplicate elements exist in input.

from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        Finds all unique combinations that sum up to target.
        
        Args:
            candidates: List of integers (with duplicates).
            target: The target sum to reach.
            
        Returns:
            List[List[int]]: A list of unique matching combinations.
        """
        candidates.sort()
        result = []
        
        def backtrack(target: int, start: int, path: List[int]):
            if target == 0:
                result.append(path[:])
                return
            
            for i in range(start, len(candidates)):
                # Early exit
                if candidates[i] > target:
                    break
                
                # Duplicate skipping
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                
                path.append(candidates[i])
                backtrack(target - candidates[i], i + 1, path)
                path.pop()
                
        backtrack(target, 0, [])
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    c1 = [10, 1, 2, 7, 6, 1, 5]
    t1 = 8
    print(f"Test 1 — Result: {sol.combinationSum2(c1, t1)}")
    # Expected: [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
