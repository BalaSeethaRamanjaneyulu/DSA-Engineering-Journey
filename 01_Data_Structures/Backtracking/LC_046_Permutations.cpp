/**
 * @file LC_046_Permutations.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 46: Permutations
 *
 * Problem: Given an array nums of distinct integers, return all the possible 
 *          permutations. You can return the answer in any order.
 *
 * Platform: LeetCode #046
 * Approach: Backtracking (State modification / Swapping)
 * Time:     O(N * N!) — There are N! permutations, each taking O(N) to copy
 * Space:    O(N)      — Due to recursive call stack depth
 * Link:     https://leetcode.com/problems/permutations/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Generates permutations by swapping elements in-place.
     *
     * We divide the array into a "fixed" part (up to 'start' index) and 
     * a "pool" part. We swap elements from the pool to the 'start' position 
     * and recursively permute the rest. Afterward, we swap back (backtrack) 
     * to explore other possibilities.
     *
     * @param nums   The current array state.
     * @param start  The index currently being chosen for the permutation.
     * @param result Master list of permutations.
     */
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: if we have fixed all positions, store this permutation.
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Try placing every element from 'start' to the end at the 'start' position
        for (int i = start; i < nums.size(); i++) {
            // Choose: Swap the current element to the 'start' position
            swap(nums[start], nums[i]);
            
            // Explore: Recursively build the rest of the permutation
            backtrack(nums, start + 1, result);
            
            // Un-choose (Backtrack): Restore the array to original state
            swap(nums[start], nums[i]);
        }
    }

    /**
     * @brief Find all permutations of the array.
     *
     * @param nums Array of distinct integers.
     * @return vector<vector<int>> A 2D array of all permutations.
     */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> res1 = sol.permute(nums1);
    cout << "Test 1 — Permutations: \n[";
    for (int i = 0; i < res1.size(); i++) {
        cout << "[";
        for (int j = 0; j < res1[i].size(); j++) {
            cout << res1[i][j] << (j < res1[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res1.size() - 1 ? ", " : "");
    }
    cout << "]\n" << endl;
    // Expected size: 6

    // Test 2: Two elements
    vector<int> nums2 = {0, 1};
    vector<vector<int>> res2 = sol.permute(nums2);
    cout << "Test 2 — Permutations: \n[";
    for (int i = 0; i < res2.size(); i++) {
        cout << "[";
        for (int j = 0; j < res2[i].size(); j++) {
            cout << res2[i][j] << (j < res2[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res2.size() - 1 ? ", " : "");
    }
    cout << "]\n" << endl;
    // Expected size: 2

    // Test 3: Array of length 1
    vector<int> nums3 = {1};
    vector<vector<int>> res3 = sol.permute(nums3);
    cout << "Test 3 — Permutations: \n[";
    for (int i = 0; i < res3.size(); i++) {
        cout << "[";
        for (int j = 0; j < res3[i].size(); j++) {
            cout << res3[i][j] << (j < res3[i].size() - 1 ? ", " : "");
        }
        cout << "]" << (i < res3.size() - 1 ? ", " : "");
    }
    cout << "]\n" << endl;

    return 0;
}
