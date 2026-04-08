/**
 * @file LC_088_Merge_Sorted_Array.cpp
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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Merges nums2 into nums1 in-place.
     *
     * To avoid overwriting elements in nums1 that haven't been processed yet,
     * we start from the back. We use three pointers:
     * - p1: Last valid element in nums1 (m - 1)
     * - p2: Last valid element in nums2 (n - 1)
     * - p: Last position in nums1 (m + n - 1)
     * 
     * We compare nums1[p1] and nums2[p2], placing the larger one at nums1[p].
     *
     * @param nums1 Vector of integers with space for m + n elements.
     * @param m     Number of original elements in nums1.
     * @param nums2 Vector of integers to merge.
     * @param n     Number of elements in nums2.
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // Pointer for nums1
        int j = n - 1;       // Pointer for nums2
        int k = m + n - 1;   // Pointer for placement in nums1

        // Compare from the back and place the largest element at the end
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

        // If any elements remain in nums2, copy them over.
        // (No need to copy remaining elements in nums1, they are already in place).
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    int m1 = 3;
    vector<int> nums2_1 = {2, 5, 6};
    int n1 = 3;
    sol.merge(nums1_1, m1, nums2_1, n1);
    cout << "Test 1 — Result: [";
    for (int i = 0; i < nums1_1.size(); i++) cout << nums1_1[i] << (i < nums1_1.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [1, 2, 2, 3, 5, 6]

    // Test 2: nums2 is empty
    vector<int> nums1_2 = {1};
    int m2 = 1;
    vector<int> nums2_2 = {};
    int n2 = 0;
    sol.merge(nums1_2, m2, nums2_2, n2);
    cout << "Test 2 — Result: [";
    for (int i = 0; i < nums1_2.size(); i++) cout << nums1_2[i] << (i < nums1_2.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [1]

    // Test 3: original elements in nums1 is 0
    vector<int> nums1_3 = {0};
    int m3 = 0;
    vector<int> nums2_3 = {1};
    int n3 = 1;
    sol.merge(nums1_3, m3, nums2_3, n3);
    cout << "Test 3 — Result: [";
    for (int i = 0; i < nums1_3.size(); i++) cout << nums1_3[i] << (i < nums1_3.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [1]

    return 0;
}
