/**
 * @file LC_051_N_Queens.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 051: N-Queens
 *
 * Problem: The n-queens puzzle is the problem of placing n queens on an 
 *          n x n chessboard such that no two queens attack each other.
 *          Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Platform: LeetCode #051
 * Approach: Backtracking (Optimized with Columns and Diagonals tracking)
 * Time:     O(N!) — The number of valid placements is drastically limited.
 * Space:    O(N^2) — For the result and the board state. (O(N) for bitsets/state).
 * Link:     https://leetcode.com/problems/n-queens/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief Recursively places queens on the board.
     *
     * Tracks constraints using three boolean vectors:
     * - columns: tracks vertical hits.
     * - diag1: tracks main diagonals (r - c is constant). Offset added for index.
     * - diag2: tracks anti-diagonals (r + c is constant).
     *
     * @param r       Current row being processed.
     * @param n       Size of the board.
     * @param board   Current board state strings.
     * @param result  Master list of valid board configurations.
     * @param cols    Tracking set for occupied columns.
     * @param diag1   Tracking set for occupied main diagonals (r - c).
     * @param diag2   Tracking set for occupied anti-diagonals (r + c).
     */
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& result,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        // Base Case: All rows processed
        if (r == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            // Check if column or diagonals are under attack
            // diag1 index: r-c + (n-1) to ensure positive index
            // diag2 index: r+c
            if (cols[c] || diag1[r - c + n - 1] || diag2[r + c]) continue;

            // Choose
            board[r][c] = 'Q';
            cols[c] = diag1[r - c + n - 1] = diag2[r + c] = true;

            // Explore
            backtrack(r + 1, n, board, result, cols, diag1, diag2);

            // Un-choose (Backtrack)
            board[r][c] = '.';
            cols[c] = diag1[r - c + n - 1] = diag2[r + c] = false;
        }
    }

    /**
     * @brief Solves the N-Queens puzzle.
     *
     * @param n Size of the board.
     * @return vector<vector<string>> List of all valid solutions.
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        
        backtrack(0, n, board, result, cols, diag1, diag2);
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: N = 4
    int n1 = 4;
    vector<vector<string>> res1 = sol.solveNQueens(n1);
    cout << "Test 1 — N = 4 (Expected 2 solutions): " << res1.size() << " found" << endl;
    for (auto& board : res1) {
        for (string row : board) cout << row << endl;
        cout << "---" << endl;
    }

    // Test 2: N = 1
    int n2 = 1;
    vector<vector<string>> res2 = sol.solveNQueens(n2);
    cout << "Test 2 — N = 1 (Expected 1 solution): " << res2.size() << " found" << endl;

    return 0;
}
