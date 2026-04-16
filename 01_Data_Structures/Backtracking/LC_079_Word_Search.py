# Problem:  Word Search
# Platform: LeetCode #079
# Approach: Backtracking (DFS on Grid)
# Time:     O(M * N * 3^L)
# Space:    O(L)
# Link:     https://leetcode.com/problems/word-search/
#
# Description:
#   Given an m x n board and a word, return True if the word exists in the 
#   board. Adjacent cells (horizontal/vertical) can be used. Each cell can 
#   be used at most once per word.

from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        Finds if the word exists in the grid using DFS.
        
        Args:
            board: 2D grid of characters.
            word: Target word string.
            
        Returns:
            bool: True if word is found, False otherwise.
        """
        rows, cols = len(board), len(board[0])
        
        def backtrack(r, c, index):
            # Base Case
            if index == len(word):
                return True
            
            # Boundary and Char check
            if (r < 0 or r >= rows or c < 0 or c >= cols or 
                board[r][c] != word[index]):
                return False
            
            # Choose: Mark visited
            temp = board[r][c]
            board[r][c] = "#"
            
            # Explore
            res = (backtrack(r + 1, c, index + 1) or
                   backtrack(r - 1, c, index + 1) or
                   backtrack(r, c + 1, index + 1) or
                   backtrack(r, c - 1, index + 1))
            
            # Backtrack
            board[r][c] = temp
            return res
            
        for i in range(rows):
            for j in range(cols):
                if backtrack(i, j, 0):
                    return True
        return False

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test cases
    board = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
    
    print(f"Test 1 — Result: {sol.exist(board, 'ABCCED')}") # True
    print(f"Test 2 — Result: {sol.exist(board, 'SEE')}")    # True
    print(f"Test 3 — Result: {sol.exist(board, 'ABCB')}")   # False
