/**
 * @file LC_079_Word_Search.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 079: Word Search
 *
 * Problem: Given an m x n grid of characters board and a string word, return 
 *          true if word exists in the grid. The word can be constructed from 
 *          letters of sequentially adjacent cells, where adjacent cells are 
 *          horizontally or vertically neighboring. The same letter cell may 
 *          not be used more than once.
 *
 * Platform: LeetCode #079
 * Approach: Backtracking (DFS on Grid)
 * Time:     O(M * N * 3^L) — where M, N are board dims, L is word length.
 *           At each step, we have 4 directions, but we don't go back, so 3 choices.
 * Space:    O(L) — recursion stack depth matches word length.
 * Link:     https://leetcode.com/problems/word-search/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief Performs DFS starting from a specific cell to find the word.
     *
     * @param r      Current row.
     * @param c      Current column.
     * @param index  Current character index in the word.
     * @param board  The character grid.
     * @param word   The target string.
     * @return true  Found the word.
     * @return false Word not found.
     */
    bool backtrack(int r, int c, int index, vector<vector<char>>& board, string& word) {
        // Base case: all characters found
        if (index == word.length()) return true;

        // Boundary and mismatch check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // Choose: Mark as visited (using a temporary char to avoid extra space)
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore: 4 directions (Up, Down, Left, Right)
        bool found = backtrack(r + 1, c, index + 1, board, word) ||
                     backtrack(r - 1, c, index + 1, board, word) ||
                     backtrack(r, c + 1, index + 1, board, word) ||
                     backtrack(r, c - 1, index + 1, board, word);

        // Un-choose (Backtrack): Restore character
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(i, j, 0, board, word)) return true;
            }
        }

        return false;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1
    vector<vector<char>> b1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string w1 = "ABCCED";
    cout << "Test 1 — Result: " << (sol.exist(b1, w1) ? "true" : "false") << endl;
    // Expected: true

    // Test 2
    string w2 = "SEE";
    cout << "Test 2 — Result: " << (sol.exist(b1, w2) ? "true" : "false") << endl;
    // Expected: true

    // Test 3
    string w3 = "ABCB";
    cout << "Test 3 — Result: " << (sol.exist(b1, w3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
