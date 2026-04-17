/**
 * @file LC_131_Palindrome_Partitioning.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 131: Palindrome Partitioning
 *
 * Problem: Partition string s such that every substring is a palindrome.
 *          Return all possible partitions.
 *
 * Platform: LeetCode #131
 * Approach: Backtracking (DFS + Partitioning)
 * Time:     O(N * 2^N)
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/palindrome-partitioning/
 */

import java.util.ArrayList;
import java.util.List;

public class LC_131_Palindrome_Partitioning {

    /**
     * Checks if substring [low, high] is palindromic.
     */
    private boolean isPalindrome(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--)) return false;
        }
        return true;
    }

    /**
     * Recursively partitions string into palindromes.
     *
     * @param start  Current slicing index.
     * @param s      Target string.
     * @param path   Current partition path.
     * @param result Full list of valid partitions.
     */
    private void backtrack(int start, String s, List<String> path, List<List<String>> result) {
        if (start == s.length()) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                path.add(s.substring(start, end + 1));
                backtrack(end + 1, s, path, result);
                path.remove(path.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        backtrack(0, s, new ArrayList<>(), result);
        return result;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_131_Palindrome_Partitioning sol = new LC_131_Palindrome_Partitioning();

        // Test 1: "aab"
        System.out.println("Test 1 — 'aab': " + sol.partition("aab"));
        // Expected: [[a, a, b], [aa, b]]
        
        // Test 2: "a"
        System.out.println("Test 2 — 'a': " + sol.partition("a"));
    }
}
