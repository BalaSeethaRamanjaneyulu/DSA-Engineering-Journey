# Problem:  N-Queens
# Platform: LeetCode #051
# Approach: Backtracking (Optimized with Columns and Diagonals sets)
# Time:     O(N!)
# Space:    O(N^2) for the result storage
# Link:     https://leetcode.com/problems/n-queens/
#
# Description:
#   Place n queens on an n x n chessboard so that no two queens attack each 
#   other. Return all distinct solutions.

from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        """
        Solves the N-Queens problem using backtracking.
        
        Args:
            n: Size of the board.
            
        Returns:
            List[List[str]]: All valid board configurations.
        """
        result = []
        board = [["." for _ in range(n)] for _ in range(n)]
        
        # State tracking for O(1) checks
        cols = set()
        diag1 = set() # (r - c) is constant
        diag2 = set() # (r + c) is constant
        
        def backtrack(r: int):
            # Base Case: all queens placed
            if r == n:
                # Convert matrix to list of strings
                copy = ["".join(row) for row in board]
                result.append(copy)
                return
            
            for c in range(n):
                # Constraint Check
                if c in cols or (r - c) in diag1 or (r + c) in diag2:
                    continue
                
                # Choose
                board[r][c] = "Q"
                cols.add(c)
                diag1.add(r - c)
                diag2.add(r + c)
                
                # Explore
                backtrack(r + 1)
                
                # Backtrack
                board[r][c] = "."
                cols.remove(c)
                diag1.remove(r - c)
                diag2.remove(r + c)
                
        backtrack(0)
        return result

# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1: N = 4
    res1 = sol.solveNQueens(4)
    print(f"Test 1 — N = 4 (Expected 2 solutions): {len(res1)} found")
    for solution in res1:
        for row in solution:
            print(row)
        print("---")
