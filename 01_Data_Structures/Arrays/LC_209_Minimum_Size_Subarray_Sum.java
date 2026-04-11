/**
 * @file LC_209_Minimum_Size_Subarray_Sum.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 209: Minimum Size Subarray Sum
 *
 * Problem: Given an array of positive integers nums and a positive integer 
 *          target, return the minimal length of a contiguous subarray 
 *          [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater 
 *          than or equal to target. If there is no such subarray, return 0 instead.
 *
 * Platform: LeetCode #209
 * Approach: Sliding Window (Two Pointers)
 * Time:     O(N)  — Each element is visited at most twice
 * Space:    O(1)  — In-place logic
 * Link:     https://leetcode.com/problems/minimum-size-subarray-sum/
 */

public class LC_209_Minimum_Size_Subarray_Sum {

    /**
     * Finds the minimum length of a subarray whose sum is >= target.
     *
     * @param target The target sum.
     * @param nums Array of positive integers.
     * @return int Minimal length of the subarray, or 0 if none found.
     */
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int minLen = Integer.MAX_VALUE;
        
        int left = 0;
        int currentSum = 0;
        
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];
            
            // Shrink the window as long as the condition is met
            while (currentSum >= target) {
                minLen = Math.min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_209_Minimum_Size_Subarray_Sum sol = new LC_209_Minimum_Size_Subarray_Sum();

        // Test 1: Standard case
        int[] nums1 = {2, 3, 1, 2, 4, 3};
        int target1 = 7;
        System.out.println("Test 1 — Minimal Length: " + sol.minSubArrayLen(target1, nums1));
        // Expected: 2 (subarray [4, 3])

        // Test 2: Exact match
        int[] nums2 = {1, 4, 4};
        int target2 = 4;
        System.out.println("Test 2 — Minimal Length: " + sol.minSubArrayLen(target2, nums2));
        // Expected: 1 (subarray [4])

        // Test 3: No valid subarray
        int[] nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
        int target3 = 11;
        System.out.println("Test 3 — Minimal Length: " + sol.minSubArrayLen(target3, nums3));
        // Expected: 0
    }
}
