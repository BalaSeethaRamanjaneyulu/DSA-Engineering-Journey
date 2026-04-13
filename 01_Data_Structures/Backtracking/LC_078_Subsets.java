/**
 * @file LC_078_Subsets.java
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

import java.util.ArrayList;
import java.util.List;

public class LC_078_Subsets {

    /**
     * Recursively generates all subsets using backtracking.
     *
     * @param nums   The original array of unique integers.
     * @param index  The current element being considered.
     * @param path   The subset currently being built.
     * @param result The master list of all valid subsets.
     */
    private void backtrack(int[] nums, int index, List<Integer> path, List<List<Integer>> result) {
        // Base Case: If we've considered all elements, add a copy of the path to our result.
        if (index == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }

        // Choice 1: INCLUDE the element at the current index
        path.add(nums[index]);
        backtrack(nums, index + 1, path, result);

        // Choice 2: EXCLUDE the element at the current index (Backtrack)
        path.remove(path.size() - 1);
        backtrack(nums, index + 1, path, result);
    }

    /**
     * Generates all possible subsets of the provided array.
     *
     * @param nums Array of unique integers.
     * @return List of List of Integers representing the power set.
     */
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(nums, 0, new ArrayList<>(), result);
        return result;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_078_Subsets sol = new LC_078_Subsets();

        // Test 1: Standard case
        int[] nums1 = {1, 2, 3};
        System.out.println("Test 1 — Subsets: \n" + sol.subsets(nums1) + "\n");
        // Expected: [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3], []]

        // Test 2: Single element
        int[] nums2 = {0};
        System.out.println("Test 2 — Subsets: \n" + sol.subsets(nums2) + "\n");
        // Expected: [[0], []]
    }
}
