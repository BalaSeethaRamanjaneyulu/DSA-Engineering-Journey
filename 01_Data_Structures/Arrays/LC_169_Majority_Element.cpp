/**
 * @file LC_169_Majority_Element.cpp
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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the majority element using Boyer-Moore Voting.
     *
     * The algorithm maintains a 'candidate' and a 'count'. When the count is 0,
     * we select the current element as the new candidate. We increment the count
     * if the current element matches the candidate, and decrement otherwise.
     * Since the majority element appears more than n/2 times, its count will
     * ultimately outbalance all other elements combined.
     *
     * @param nums Vector of integers.
     * @return int The majority element.
     */
    int majorityElement(vector<int>& nums) {
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
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {3, 2, 3};
    cout << "Test 1 — Majority Element: " << sol.majorityElement(nums1) << endl;
    // Expected: 3

    // Test 2: Standard case with more occurrences
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test 2 — Majority Element: " << sol.majorityElement(nums2) << endl;
    // Expected: 2

    // Test 3: Array of length 1
    vector<int> nums3 = {5};
    cout << "Test 3 — Majority Element: " << sol.majorityElement(nums3) << endl;
    // Expected: 5

    return 0;
}
