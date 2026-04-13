/**
 * @file LC_078_Subsets.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 078: Subsets
 *
 * Problem: Given an integer array nums of unique elements, return all possible
 *          subsets (the power set). The solution set must not contain duplicate
 *          subsets. Return the solution in any order.
 *
 * Platform: LeetCode #078
 * Approach: Backtracking (Pick & Don't Pick)
 * Time:     O(N * 2^N) — Generating all 2^N subsets, each taking up to O(N) to copy
 * Space:    O(N)       — Execution call stack and current subset path
 * Link:     https://leetcode.com/problems/subsets/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Recursively generates all subsets using backtracking.
     * 
     * At each step (index), we have two choices:
     * 1. Include the current element in our path and recurse.
     * 2. Exclude the current element (backtrack) and recurse.
     *
     * @param nums   The original array of unique integers.
     * @param index  The current element being considered.
     * @param path   The subset currently being built.
     * @param result The master list of all valid subsets.
     */
    void backtrack(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& result) {
        // Base Case: If we've considered all elements, add the path to our result.
        if (index == nums.size()) {
            result.push_back(path);
            return;
        }

        // Choice 1: INCLUDE the element at the current index
        path.push_back(nums[index]);
        backtrack(nums, index + 1, path, result);

        // Choice 2: EXCLUDE the element at the current index (Backtrack)
        path.pop_back();
        backtrack(nums, index + 1, path, result);
    }

    /**
     * @brief Generates all possible subsets of the provided array.
     *
     * @param nums Vector of unique integers.
     * @return vector<vector<int>> A 2D array representing the power set.
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> res1 = sol.subsets(nums1);
    cout << "Test 1 — Subsets: \n[";
    for (int i = 0; i < res1.size(); i++) {
        cout << "[";
        for (int j = 0; j < res1[i].size(); j++) {
            cout << res1[i][j] << (j < res1[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]\n" << endl;
    // Expected: [[1,2,3], [1,2], [1,3], [1], [2,3], [2], [3], []]

    // Test 2: Single element
    vector<int> nums2 = {0};
    vector<vector<int>> res2 = sol.subsets(nums2);
    cout << "Test 2 — Subsets: \n[";
    for (int i = 0; i < res2.size(); i++) {
        cout << "[";
        for (int j = 0; j < res2[i].size(); j++) {
            cout << res2[i][j] << (j < res2[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]\n" << endl;
    // Expected: [[0], []]

    return 0;
}
