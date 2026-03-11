/**
 * @file LC_026_Remove_Duplicates_from_Sorted_Array.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 026: Remove Duplicates from Sorted Array
 *
 * Problem: Given an integer array nums sorted in non-decreasing order, remove
 *          the duplicates in-place such that each unique element appears only once.
 *          The relative order of the elements should be kept the same.
 *          Then return the number of unique elements in nums.
 *
 * Platform: LeetCode #026
 * Approach: Two Pointers
 * Time:     O(N)  — single pass
 * Space:    O(1)  — in-place
 * Link:     https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

import java.util.Arrays;

public class LC_026_Remove_Duplicates_from_Sorted_Array {

    /**
     * Removes duplicates from a sorted array in-place.
     *
     * @param nums Array of integers sorted in non-decreasing order.
     * @return int Number of unique elements.
     */
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;

        int i = 0; // next position for a unique element
        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_026_Remove_Duplicates_from_Sorted_Array sol = new LC_026_Remove_Duplicates_from_Sorted_Array();

        // Test 1
        int[] nums1 = {1, 1, 2};
        int k1 = sol.removeDuplicates(nums1);
        System.out.println("Test 1 — k: " + k1 + ", result: " + Arrays.toString(Arrays.copyOfRange(nums1, 0, k1)));
        // Expected: 2, [1, 2]

        // Test 2
        int[] nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k2 = sol.removeDuplicates(nums2);
        System.out.println("Test 2 — k: " + k2 + ", result: " + Arrays.toString(Arrays.copyOfRange(nums2, 0, k2)));
        // Expected: 5, [0, 1, 2, 3, 4]
    }
}
