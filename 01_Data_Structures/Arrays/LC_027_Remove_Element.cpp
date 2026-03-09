/**
 * @file LC_027_Remove_Element.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 027: Remove Element
 * @version 0.1
 * @date 2026-03-09
 *
 * Problem: Given an integer array nums and an integer val, remove all
 *          occurrences of val in nums in-place. The relative order of
 *          the other elements may be changed. Return k, the count of
 *          elements not equal to val.
 *
 * Platform: LeetCode #27
 * Approach: Two Pointers (slow/fast write pointer)
 * Time:     O(N)  — single pass through the array
 * Space:    O(1)  — in-place, no extra storage
 * Link:     https://leetcode.com/problems/remove-element/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Removes all occurrences of val from nums in-place.
     *
     * Uses a "write pointer" (k) that only advances when the current
     * element is NOT equal to val, effectively overwriting unwanted
     * values with the next valid element.
     *
     * @param nums Reference to the array of integers.
     * @param val  The value to erase / remove.
     * @return int Number of elements remaining after removal.
     */
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // write pointer — points to the next valid slot

        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // copy valid element to front
                k++;
            }
            // If nums[i] == val, we simply skip it (erase it logically)
        }

        return k; // first k elements of nums[] are the result
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test case 1: standard erase
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = sol.removeElement(nums1, val1);
    cout << "Test 1 — k = " << k1 << ", result: [";
    for (int i = 0; i < k1; i++) cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: k=2, result=[2, 2]

    // Test case 2: typical mixed array
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);
    cout << "Test 2 — k = " << k2 << ", result: [";
    for (int i = 0; i < k2; i++) cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: k=5, result=[0, 1, 3, 0, 4]

    // Test case 3: all elements equal val (nothing survives)
    vector<int> nums3 = {7, 7, 7};
    int val3 = 7;
    int k3 = sol.removeElement(nums3, val3);
    cout << "Test 3 — k = " << k3 << " (expected 0)" << endl;

    // Test case 4: val not present (nothing erased)
    vector<int> nums4 = {1, 2, 3};
    int val4 = 9;
    int k4 = sol.removeElement(nums4, val4);
    cout << "Test 4 — k = " << k4 << " (expected 3)" << endl;

    return 0;
}
