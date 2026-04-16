/**
 * @file LC_040_Combination_Sum_II.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 040: Combination Sum II
 *
 * Problem: Given a collection of candidate numbers (candidates) and a target 
 *          number (target), find all unique combinations in candidates where 
 *          the candidate numbers sum to target. Each number in candidates 
 *          may only be used once in the combination.
 *          Note: The solution set must not contain duplicate combinations.
 *
 * Platform: LeetCode #040
 * Approach: Backtracking (Sort + Duplicate Skipping)
 * Time:     O(2^N * N) — where N is the number of candidates
 * Space:    O(N)       — recursive stack depth
 * Link:     https://leetcode.com/problems/combination-sum-ii/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Recursively finds unique combinations that sum to target.
     *
     * To handle duplicates and avoid duplicate combinations, we first sort the
     * array. Then in the recursion loop, we skip the same element if it has
     * already been processed as a starting candidate in the current depth.
     *
     * @param target     Remaining sum to reach.
     * @param start      Index to begin the search to ensure only unique choices.
     * @param candidates The sorted input array.
     * @param path       Current path of chosen integers.
     * @param result     Final container for all unique combinations.
     */
    void backtrack(int target, int start, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
        // Base case: target hit
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Early exit: since array is sorted, we can't find further matches
            if (candidates[i] > target) break;

            // Skip duplicates: if current element is same as previous in this loop, 
            // the result would be a duplicate tree.
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Choose
            path.push_back(candidates[i]);
            
            // Explore: move to index i+1 to ensure each element is used only once
            backtrack(target - candidates[i], i + 1, candidates, path, result);
            
            // Un-choose (Backtrack)
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Essential for duplicate skipping
        vector<vector<int>> result;
        vector<int> path;
        backtrack(target, 0, candidates, path, result);
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Contains duplicates
    vector<int> c1 = {10, 1, 2, 7, 6, 1, 5};
    int t1 = 8;
    vector<vector<int>> res1 = sol.combinationSum2(c1, t1);
    cout << "Test 1 — Result: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << "[";
        for (int j = 0; j < res1[i].size(); j++) {
            cout << res1[i][j] << (j < res1[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]

    // Test 2: Standard case
    vector<int> c2 = {2, 5, 2, 1, 2};
    int t2 = 5;
    vector<vector<int>> res2 = sol.combinationSum2(c2, t2);
    cout << "Test 2 — Result: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << "[";
        for (int j = 0; j < res2[i].size(); j++) {
            cout << res2[i][j] << (j < res2[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [[1, 2, 2], [5]]

    return 0;
}
