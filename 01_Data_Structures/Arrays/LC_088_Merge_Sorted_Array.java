/**
 * @file LC_088_Merge_Sorted_Array.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 088: Merge Sorted Array
 *
 * Problem: You are given two integer arrays nums1 and nums2, sorted in 
 *          non-decreasing order, and two integers m and n, representing the 
 *          number of elements in nums1 and nums2 respectively. Merge nums1 
 *          and nums2 into a single array sorted in non-decreasing order.
 *          The final sorted array should be stored inside the array nums1.
 *
 * Platform: LeetCode #088
 * Approach: Three Pointers (Iterate Backwards)
 * Time:     O(m + n)  — single pass from the end
 * Space:    O(1)  — in-place modification
 * Link:     https://leetcode.com/problems/merge-sorted-array/
 */

import java.util.Arrays;

public class LC_088_Merge_Sorted_Array {

    /**
     * Merges nums2 into nums1 in-place.
     *
     * @param nums1 Integer array with size m + n.
     * @param m     Number of original elements in nums1.
     * @param nums2 Integer array to be merged.
     * @param n     Number of elements in nums2.
     */
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;       // Pointer for nums1 valid elements
        int j = n - 1;       // Pointer for nums2
        int k = m + n - 1;   // Pointer for placements in nums1

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy any remaining elements from nums2.
        // Elements remaining in nums1 are already in the correct place.
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_088_Merge_Sorted_Array sol = new LC_088_Merge_Sorted_Array();

        // Test 1
        int[] nums1_1 = {1, 2, 3, 0, 0, 0};
        int m1 = 3;
        int[] nums2_1 = {2, 5, 6};
        int n1 = 3;
        sol.merge(nums1_1, m1, nums2_1, n1);
        System.out.println("Test 1 — Result: " + Arrays.toString(nums1_1));
        // Expected: [1, 2, 2, 3, 5, 6]

        // Test 2
        int[] nums1_2 = {1};
        int m2 = 1;
        int[] nums2_2 = {};
        int n2 = 0;
        sol.merge(nums1_2, m2, nums2_2, n2);
        System.out.println("Test 2 — Result: " + Arrays.toString(nums1_2));
        // Expected: [1]

        // Test 3
        int[] nums1_3 = {0};
        int m3 = 0;
        int[] nums2_3 = {1};
        int n3 = 1;
        sol.merge(nums1_3, m3, nums2_3, n3);
        System.out.println("Test 3 — Result: " + Arrays.toString(nums1_3));
        // Expected: [1]
    }
}
