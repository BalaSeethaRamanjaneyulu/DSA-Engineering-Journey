
/**
 * @file LC_027_Remove_Element.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 027: Remove Element
 *
 * Problem: Given an integer array nums and an integer val, remove all
 *          occurrences of val in nums in-place. The relative order of
 *          the other elements may be changed. Return k, the count of
 *          elements not equal to val.
 *
 * Platform: LeetCode #27
 * Approach: Two Pointers (write-pointer / slow-fast pointer)
 * Time:     O(N)  — single pass through the array
 * Space:    O(1)  — in-place, no extra storage
 * Link:     https://leetcode.com/problems/remove-element/
 */

import java.util.Arrays;

public class LC_027_Remove_Element {

    /**
     * Removes all occurrences of val from nums in-place.
     *
     * <p>
     * A write pointer {@code k} tracks the next position for a valid
     * element. Whenever the current element is NOT val, it is copied to
     * {@code nums[k]} and k advances. Elements equal to val are simply
     * skipped — logically erased.
     * </p>
     *
     * @param nums The array to modify in-place.
     * @param val  The value to erase / remove.
     * @return The count k of elements that are not equal to val.
     */
    public int removeElement(int[] nums, int val) {
        int k = 0; // write pointer — points to the next valid slot

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // place valid element at the write position
                k++;
            }
            // nums[i] == val → skip (erase) it by not advancing k
        }

        return k; // first k elements of nums[] are the answer
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_027_Remove_Element sol = new LC_027_Remove_Element();

        // Test 1: standard erase
        int[] nums1 = { 3, 2, 2, 3 };
        int val1 = 3;
        int k1 = sol.removeElement(nums1, val1);
        System.out.println("Test 1 — k = " + k1
                + ", result: " + Arrays.toString(Arrays.copyOfRange(nums1, 0, k1)));
        // Expected: k=2, result=[2, 2]

        // Test 2: typical mixed array
        int[] nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
        int val2 = 2;
        int k2 = sol.removeElement(nums2, val2);
        System.out.println("Test 2 — k = " + k2
                + ", result: " + Arrays.toString(Arrays.copyOfRange(nums2, 0, k2)));
        // Expected: k=5, result=[0, 1, 3, 0, 4]

        // Test 3: all elements equal val (nothing survives)
        int[] nums3 = { 7, 7, 7 };
        int val3 = 7;
        int k3 = sol.removeElement(nums3, val3);
        System.out.println("Test 3 — k = " + k3 + " (expected 0)");

        // Test 4: val not present (nothing erased)
        int[] nums4 = { 1, 2, 3 };
        int val4 = 9;
        int k4 = sol.removeElement(nums4, val4);
        System.out.println("Test 4 — k = " + k4 + " (expected 3)");
    }
}
