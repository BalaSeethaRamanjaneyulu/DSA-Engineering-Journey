/**
 * @file LC_039_Combination_Sum.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 039: Combination Sum
 *
 * Problem: Given an array of distinct integers candidates and a target integer 
 *          target, return a list of all unique combinations of candidates where 
 *          the chosen numbers sum to target. You may return the combinations 
 *          in any order. The same number may be chosen from candidates an 
 *          unlimited number of times.
 *
 * Platform: LeetCode #039
 * Approach: Backtracking (Pick or Skip)
 * Time:     O(2^t * k) where t is target/min_candidate and k is avg combination length
 * Space:    O(t)       where t is the depth of the recursion tree
 * Link:     https://leetcode.com/problems/combination-sum/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Recursively explores combinations that sum to the target.
     *
     * @param index      Current candidate being considered.
     * @param target     Remaining sum needed.
     * @param candidates Available numbers.
     * @param path       Current chosen path of numbers.
     * @param result     List of all successful combinations.
     */
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
        // Base Case 1: We hit the exact target
        if (target == 0) {
            result.push_back(path);
            return;
        }

        // Base Case 2: We exceeded the target or ran out of candidates
        if (target < 0 || index == candidates.size()) {
            return;
        }

        // Choice 1: PICK the current element (unlimited usage supported)
        path.push_back(candidates[index]);
        // Stay at same index to allow picking it again
        backtrack(index, target - candidates[index], candidates, path, result);
        // Backtrack (remove element)
        path.pop_back();

        // Choice 2: SKIP the current element and move to the next
        backtrack(index + 1, target, candidates, path, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(0, target, candidates, path, result);
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: standard usage
    vector<int> c1 = {2, 3, 6, 7};
    int t1 = 7;
    vector<vector<int>> res1 = sol.combinationSum(c1, t1);
    cout << "Test 1 — Result: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << "[";
        for (int j = 0; j < res1[i].size(); j++) {
            cout << res1[i][j] << (j < res1[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    // Expected: [[2, 2, 3], [7]]

    return 0;
}
