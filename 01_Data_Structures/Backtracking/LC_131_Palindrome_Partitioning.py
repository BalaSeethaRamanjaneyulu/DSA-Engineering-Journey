# Problem:  Palindrome Partitioning
# Platform: LeetCode #131
# Approach: Backtracking (DFS + String Slicing)
# Time:     O(N * 2^N)
# Space:    O(N)
# Link:     https://leetcode.com/problems/palindrome-partitioning/
#
# Description:
#   Given a string s, partition s such that every substring of the partition 
#   is a palindrome. Return all possible palindrome partitioning of s.

from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        """
        Partitions the string into palindromic segments using backtracking.
        
        Args:
            s: Input string.
            
        Returns:
            List[List[str]]: All valid palindromic partitioning solutions.
        """
        result = []
        
        def is_palindrome(segment: str) -> bool:
            return segment == segment[::-1]
            
        def backtrack(start: int, path: List[str]):
            # Base Case: end of string reached
            if start == len(s):
                result.append(path[:])
                return
            
            for end in range(start + 1, len(s) + 1):
                segment = s[start:end]
                if is_palindrome(segment):
                    # Choose
                    path.append(segment)
                    # Explore
                    backtrack(end, path)
                    # Backtrack
                    path.pop()
                    
        backtrack(0, [])
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1
    s1 = "aab"
    print(f"Test 1 — 'aab': {sol.partition(s1)}")
    # Expected: [['a', 'a', 'b'], ['aa', 'b']]
    
    # Test 2
    s2 = "a"
    print(f"Test 2 — 'a': {sol.partition(s2)}")
