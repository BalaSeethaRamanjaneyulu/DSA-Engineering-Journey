/**
 * @file LC_039_Combination_Sum.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 039: Combination Sum
 *
 * Problem: Given an array of distinct integers candidates and a target integer 
 *          target, return a list of all unique combinations of candidates where 
 *          the chosen numbers sum to target. The same number may be chosen from 
 *          candidates an unlimited number of times.
 *
 * Platform: LeetCode #039
 * Approach: Backtracking (Pick or Skip)
 * Time:     O(2^t * k) where t is target/min_candidate
 * Space:    O(target) due to recursive depth
 * Link:     https://leetcode.com/problems/combination-sum/
 */

import java.util.ArrayList;
import java.util.List;

public class LC_039_Combination_Sum {

    /**
     * Finds all unique combinations that sum up to target.
     *
     * @param index      Current index in the candidates array.
     * @param target     Current target we are trying to reach.
     * @param candidates Array of possible numbers to use.
     * @param current    The combination we are building.
     * @param result     The final list of valid combinations.
     */
    private void findCombinations(int index, int target, int[] candidates, List<Integer> current, List<List<Integer>> result) {
        // Base case: we successfully hit target
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        // Base case: we ran out of options or exceeded target
        if (index == candidates.length || target < 0) {
            return;
        }

        // Choice 1: PICK the element at index. 
        // We stay at index because we can reuse the element.
        current.add(candidates[index]);
        findCombinations(index, target - candidates[index], candidates, current, result);
        // Backtrack
        current.remove(current.size() - 1);

        // Choice 2: SKIP the element at index and move to next one.
        findCombinations(index + 1, target, candidates, current, result);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        findCombinations(0, target, candidates, new ArrayList<>(), result);
        return result;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_039_Combination_Sum sol = new LC_039_Combination_Sum();

        int[] candidates = {2, 3, 6, 7};
        int target = 7;
        
        System.out.println("Test 1 — Result: " + sol.combinationSum(candidates, target));
        // Expected output: [[2, 2, 3], [7]]
    }
}
