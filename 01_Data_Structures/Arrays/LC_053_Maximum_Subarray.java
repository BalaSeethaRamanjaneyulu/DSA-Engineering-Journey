/**
 * @file LC_053_Maximum_Subarray.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 053: Maximum Subarray
 *
 * Problem: Given an integer array nums, find the subarray with the largest sum,
 *          and return its sum.
 *
 * Platform: LeetCode #053
 * Approach: Kadane's Algorithm (Dynamic Programming / Greedy)
 * Time:     O(N)  — single pass through the array
 * Space:    O(1)  — no extra space needed
 * Link:     https://leetcode.com/problems/maximum-subarray/
 */

public class LC_053_Maximum_Subarray {

    /**
     * Finds the subarray with the largest sum.
     *
     * @param nums Array of integers.
     * @return int  Maximum subarray sum.
     */
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum < 0) {
                currentSum = 0;
            }
            currentSum += num;
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_053_Maximum_Subarray sol = new LC_053_Maximum_Subarray();

        // Test 1: standard case with mixed positive and negative numbers
        int[] nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Test 1 — Max Subarray Sum: " + sol.maxSubArray(nums1));
        // Expected: 6 (subarray [4, -1, 2, 1])

        // Test 2: single element
        int[] nums2 = {1};
        System.out.println("Test 2 — Max Subarray Sum: " + sol.maxSubArray(nums2));
        // Expected: 1

        // Test 3: all elements negative
        int[] nums3 = {-5, -1, -3};
        System.out.println("Test 3 — Max Subarray Sum: " + sol.maxSubArray(nums3));
        // Expected: -1
    }
}
