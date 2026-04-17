/**
 * @file LC_131_Palindrome_Partitioning.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 131: Palindrome Partitioning
 *
 * Problem: Given a string s, partition s such that every substring of the 
 *          partition is a palindrome. Return all possible palindrome 
 *          partitioning of s.
 *
 * Platform: LeetCode #131
 * Approach: Backtracking (DFS + Slicing)
 * Time:     O(N * 2^N) — In the worst case, every substring is a palindrome (e.g., "aaa").
 * Space:    O(N)       — Recursion depth.
 * Link:     https://leetcode.com/problems/palindrome-partitioning/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Checks if a substring is a palindrome.
     */
    bool isPalindrome(const string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }

    /**
     * @brief Recursively partitions the string.
     *
     * @param start  Starting index of the current partition.
     * @param s      Original string.
     * @param path   Current partitioning path.
     * @param result Master list of all valid partitions.
     */
    void backtrack(int start, string& s, vector<string>& path, vector<vector<string>>& result) {
        // Base Case: start reached the end of the string
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            // Check if the current slice [start, end] is a palindrome
            if (isPalindrome(s, start, end)) {
                // Choose
                path.push_back(s.substr(start, end - start + 1));
                
                // Explore
                backtrack(end + 1, s, path, result);
                
                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1
    string s1 = "aab";
    vector<vector<string>> res1 = sol.partition(s1);
    cout << "Test 1 — 'aab': " << endl;
    for (auto& p : res1) {
        cout << "[";
        for (int i = 0; i < p.size(); i++) cout << p[i] << (i < p.size() - 1 ? ", " : "");
        cout << "]" << endl;
    }
    // Expected: [[a, a, b], [aa, b]]

    // Test 2
    string s2 = "a";
    vector<vector<string>> res2 = sol.partition(s2);
    cout << "Test 2 — 'a': " << res2.size() << " solutions" << endl;

    return 0;
}
