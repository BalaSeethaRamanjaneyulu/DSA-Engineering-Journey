/**
 * @file LC_026_Remove_Duplicates_from_Sorted_Array.cpp
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
 * Time:     O(N)  — one pass through the array
 * Space:    O(1)  — in-place modification
 * Link:     https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Removes duplicates from a sorted array in-place.
     *
     * Uses two pointers: 'i' tracks the position of the last unique element found,
     * and 'j' iterates through the array seeking new unique elements.
     *
     * @param nums Vector of sorted integers.
     * @return int  Number of unique elements.
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0; // index of the last unique element
        for (int j = 1; j < (int)nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: standard case
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Test 1 — k: " << k1 << ", result: [";
    for (int i = 0; i < k1; i++) cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: 2, [1, 2]

    // Test 2: multiple duplicates
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "Test 2 — k: " << k2 << ", result: [";
    for (int i = 0; i < k2; i++) cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: 5, [0, 1, 2, 3, 4]

    return 0;
}
