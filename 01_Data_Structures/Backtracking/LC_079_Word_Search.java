/**
 * @file LC_079_Word_Search.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 079: Word Search
 * 
 * Problem: Find if a word exists in a grid of characters (adjacent horizontally/vertically).
 *          Each cell can be used only once per word.
 *
 * Platform: LeetCode #079
 * Approach: Backtracking (DFS on Grid)
 * Time:     O(M * N * 3^L)
 * Space:    O(L)
 * Link:     https://leetcode.com/problems/word-search/
 */

public class LC_079_Word_Search {

    /**
     * DFS exploring the grid for the target word.
     *
     * @param r      Row index.
     * @param c      Column index.
     * @param index  Character index in word.
     * @param board  Grid of characters.
     * @param word   Target word.
     * @return boolean True if found.
     */
    private boolean backtrack(int r, int c, int index, char[][] board, String word) {
        if (index == word.length()) return true;

        if (r < 0 || r >= board.length || c < 0 || c >= board[0].length || board[r][c] != word.charAt(index)) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark as visited

        boolean found = backtrack(r + 1, c, index + 1, board, word) ||
                        backtrack(r - 1, c, index + 1, board, word) ||
                        backtrack(r, c + 1, index + 1, board, word) ||
                        backtrack(r, c - 1, index + 1, board, word);

        board[r][c] = temp; // Backtrack: Restore state
        return found;
    }

    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backtrack(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_079_Word_Search sol = new LC_079_Word_Search();

        char[][] board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        
        System.out.println("Test 1 — Result: " + sol.exist(board, "ABCCED")); // true
        System.out.println("Test 2 — Result: " + sol.exist(board, "SEE"));    // true
        System.out.println("Test 3 — Result: " + sol.exist(board, "ABCB"));   // false
    }
}
