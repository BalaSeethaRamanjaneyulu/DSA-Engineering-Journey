/**
 * @file LC_046_Permutations.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 46: Permutations
 *
 * Problem: Given an array nums of distinct integers, return all the possible 
 *          permutations. You can return the answer in any order.
 *
 * Platform: LeetCode #046
 * Approach: Backtracking (Using a visited array & path generation)
 * Time:     O(N * N!) — There are N! permutations, each taking O(N) to copy
 * Space:    O(N)      — Execution call stack depth and visited array
 * Link:     https://leetcode.com/problems/permutations/
 */

import java.util.ArrayList;
import java.util.List;

public class LC_046_Permutations {

    /**
     * Recursively generates permutations by tracking visited elements.
     *
     * @param nums    Array of distinct integers.
     * @param path    The permutation currently being built.
     * @param visited Array tracking which indices have been used.
     * @param result  Master list of permutations.
     */
    private void backtrack(int[] nums, List<Integer> path, boolean[] visited, List<List<Integer>> result) {
        // Base case: the path length matches nums length, we have a complete permutation
        if (path.size() == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // Skip elements that are already in the current path
            if (visited[i]) continue;

            // Choose: Mark as visited and add to path
            visited[i] = true;
            path.add(nums[i]);

            // Explore: Recursively build the rest of the permutation
            backtrack(nums, path, visited, result);

            // Un-choose (Backtrack): Unmark and remove from path
            visited[i] = false;
            path.remove(path.size() - 1);
        }
    }

    /**
     * Find all permutations of the array.
     *
     * @param nums Array of distinct integers.
     * @return A List of Lists of all permutations.
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(nums, new ArrayList<>(), new boolean[nums.length], result);
        return result;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_046_Permutations sol = new LC_046_Permutations();

        // Test 1: Standard case
        int[] nums1 = {1, 2, 3};
        System.out.println("Test 1 — Permutations: \n" + sol.permute(nums1) + "\n");
        // Expected size: 6

        // Test 2: Two elements
        int[] nums2 = {0, 1};
        System.out.println("Test 2 — Permutations: \n" + sol.permute(nums2) + "\n");
        // Expected size: 2

        // Test 3: Array of length 1
        int[] nums3 = {1};
        System.out.println("Test 3 — Permutations: \n" + sol.permute(nums3) + "\n");
    }
}
