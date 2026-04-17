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
        Solves the N-Queens problem using optimized backtracking.
        
        This implementation uses bit-tracking logic simulated with sets to maintain 
        O(1) lookups for column and diagonal constraints.
        
        Args:
            n (int): The number of queens to place on an n x n board.
            
        Returns:
            List[List[str]]: A list of all unique board configurations where 
            queens do not attack each other. Each solution is represented as 
            a list of strings.
            
        Complexity:
            Time: O(N!) - We explore permutations, but pruned by constraints.
            Space: O(N^2) - For the board state and result storage.
        """
        result = []
        board = [["." for _ in range(n)] for _ in range(n)]
        
        # Optimized Constraint Tracking
        # 1. cols: tracks vertical hits.
        # 2. diag1 (Main): r - c is constant for all cells on same main diagonal.
        # 3. diag2 (Anti): r + c is constant for all cells on same anti-diagonal.
        cols = set()
        diag1 = set() 
        diag2 = set() 
        
        def backtrack(r: int):
            # Base Case: If we've reached the row 'n', all queens are placed.
            if r == n:
                # Build the board representation strings.
                result.append(["".join(row) for row in board])
                return
            
            for c in range(n):
                # Standard Pruning: Check if column or diagonals are already occupied.
                if c in cols or (r - c) in diag1 or (r + c) in diag2:
                    continue
                
                # 1. Choose: Place the queen and mark constraints.
                board[r][c] = "Q"
                cols.add(c)
                diag1.add(r - c)
                diag2.add(r + c)
                
                # 2. Explore: Move down to the next row.
                backtrack(r + 1)
                
                # 3. Backtrack: Undo the placement for the next iteration.
                board[r][c] = "."
                cols.remove(c)
                diag1.remove(r - c)
                diag2.remove(r + c)
                
        backtrack(0)
        return result

# ─── Technical Analysis ──────────────────────────────────────────────────────
#
# Constraints Check Logic:
# ------------------------
# 1. Vertical Check: Simply check if the column index 'c' has been used before.
# 2. Main Diagonal (\): In any N x N grid, move down-right means r++ and c++. 
#    Thus, the difference (r - c) remains constant.
# 3. Anti-Diagonal (/): move down-left means r++ and c--.
#    Thus, the sum (r + c) remains constant.
#
# Logic of (r - c):
#   For (0,0) -> 0; (1,1) -> 0; (2,2) -> 0
#   For (0,1) -> -1; (1,2) -> -1; (2,3) -> -1
# 
# ─── Dry Run Trace (N=4) ──────────────────────────────────────────────────────
#
# Level 0 (Row 0): Try c=0. [Q...] 
#   Level 1 (Row 1): c=0 (X), c=1 (X), c=2 (OK). [Q...],[..Q.]
#     Level 2 (Row 2): All cols blocked. BACKTRACK.
#   Level 1 (Row 1): c=3 (OK). [Q...],[...Q]
#     Level 2 (Row 2): c=0 (X), c=1 (OK). [Q...],[...Q],[.Q..]
#       Level 3 (Row 3): All cols blocked. BACKTRACK.
# ... Resulting in 2 valid solutions found.
#
# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1: N = 4
    res1 = sol.solveNQueens(4)
    print(f"Test 1 — N = 4 (Expected 2 solutions): {len(res1)} found")
    for idx, solution in enumerate(res1):
        print(f"Solution {idx + 1}:")
        for row in solution:
            print(row)
        print("---")
