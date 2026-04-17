/**
 * @file LC_051_N_Queens.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 051: N-Queens
 * 
 * Problem: Place n queens on an n x n board such that no two queens attack.
 *          Return all distinct solutions.
 *
 * Platform: LeetCode #051
 * Approach: Backtracking with O(1) Constraint Checking
 * Time:     O(N!)
 * Space:    O(N^2) for result storage
 * Link:     https://leetcode.com/problems/n-queens/
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC_051_N_Queens {

    /**
     * Backtracking function to place queens row by row.
     *
     * @param r      Current row.
     * @param n      Board size.
     * @param board  Current board state as char array.
     * @param res    Final solutions list.
     * @param cols   Boolean array for occupied columns.
     * @param diag1  Boolean array for occupied main diagonals (r - c).
     * @param diag2  Boolean array for occupied anti-diagonals (r + c).
     */
    private void backtrack(int r, int n, char[][] board, List<List<String>> res, 
                           boolean[] cols, boolean[] diag1, boolean[] diag2) {
        if (r == n) {
            res.add(construct(board));
            return;
        }

        for (int c = 0; c < n; c++) {
            // Main diagonal index: r - c + (n - 1)
            // Anti-diagonal index: r + c
            if (cols[c] || diag1[r - c + n - 1] || diag2[r + c]) continue;

            // Choose
            board[r][c] = 'Q';
            cols[c] = diag1[r - c + n - 1] = diag2[r + c] = true;

            // Explore
            backtrack(r + 1, n, board, res, cols, diag1, diag2);

            // Backtrack
            board[r][c] = '.';
            cols[c] = diag1[r - c + n - 1] = diag2[r + c] = false;
        }
    }

    /**
     * Helper to convert the char board into the required List of Strings format.
     */
    private List<String> construct(char[][] board) {
        List<String> path = new ArrayList<>();
        for (char[] row : board) {
            path.add(new String(row));
        }
        return path;
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        char[][] board = new char[n][n];
        for (char[] row : board) Arrays.fill(row, '.');

        boolean[] cols = new boolean[n];
        boolean[] diag1 = new boolean[2 * n - 1];
        boolean[] diag2 = new boolean[2 * n - 1];

        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_051_N_Queens sol = new LC_051_N_Queens();

        // Test 1: N = 4
        List<List<String>> res1 = sol.solveNQueens(4);
        System.out.println("Test 1 — N = 4 (Expected 2 solutions): " + res1.size() + " found");
        for (List<String> solution : res1) {
            for (String row : solution) System.out.println(row);
            System.out.println("---");
        }
    }
}
