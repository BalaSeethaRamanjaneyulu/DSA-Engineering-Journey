/**
 * @file LC_040_Combination_Sum_II.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 040: Combination Sum II
 *
 * Problem: Given a collection of candidate numbers (candidates) and a target 
 *          number (target), find all unique combinations in candidates where 
 *          the candidate numbers sum to target. Each number in candidates 
 *          may only be used once in the combination.
 *
 * Platform: LeetCode #040
 * Approach: Backtracking (Sort + Duplicate Skipping)
 * Time:     O(2^N * N)
 * Space:    O(N)
 * Link:     https://leetcode.com/problems/combination-sum-ii/
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC_040_Combination_Sum_II {

    /**
     * Recursively finds unique combinations that sum up to target.
     *
     * @param target     Remaining sum.
     * @param start      Starting index to check candidates.
     * @param candidates Sorted input array.
     * @param path       Current combination path.
     * @param result     Final list of unique combinations.
     */
    private void backtrack(int target, int start, int[] candidates, List<Integer> path, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            // Early exit
            if (candidates[i] > target) break;

            // Duplicate skipping: check if same starting element was already tried 
            // at this recursive depth.
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            path.add(candidates[i]);
            backtrack(target - candidates[i], i + 1, candidates, path, result);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        backtrack(target, 0, candidates, new ArrayList<>(), result);
        return result;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_040_Combination_Sum_II sol = new LC_040_Combination_Sum_II();

        int[] c1 = {10, 1, 2, 7, 6, 1, 5};
        int t1 = 8;
        System.out.println("Test 1 — Result: " + sol.combinationSum2(c1, t1));
        // Expected: [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
    }
}
