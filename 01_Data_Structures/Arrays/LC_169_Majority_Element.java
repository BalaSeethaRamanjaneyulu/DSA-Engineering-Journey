/**
 * @file LC_169_Majority_Element.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 169: Majority Element
 *
 * Problem: Given an array nums of size n, return the majority element.
 *          The majority element is the element that appears more than ⌊n / 2⌋ times.
 *          You may assume that the majority element always exists in the array.
 *
 * Platform: LeetCode #169
 * Approach: Boyer-Moore Voting Algorithm
 * Time:     O(N)  — Single pass through the array
 * Space:    O(1)  — No extra space needed
 * Link:     https://leetcode.com/problems/majority-element/
 */

public class LC_169_Majority_Element {

    /**
     * Finds the majority element using Boyer-Moore Voting.
     *
     * @param nums Array of integers.
     * @return int The majority element.
     */
    public int majorityElement(int[] nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_169_Majority_Element sol = new LC_169_Majority_Element();

        // Test 1: Standard case
        int[] nums1 = {3, 2, 3};
        System.out.println("Test 1 — Majority Element: " + sol.majorityElement(nums1));
        // Expected: 3

        // Test 2: Standard case with more occurrences
        int[] nums2 = {2, 2, 1, 1, 1, 2, 2};
        System.out.println("Test 2 — Majority Element: " + sol.majorityElement(nums2));
        // Expected: 2

        // Test 3: Array of length 1
        int[] nums3 = {5};
        System.out.println("Test 3 — Majority Element: " + sol.majorityElement(nums3));
        // Expected: 5
    }
}
