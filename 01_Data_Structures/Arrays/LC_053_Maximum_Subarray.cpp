/**
 * @file LC_053_Maximum_Subarray.cpp
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the subarray with the largest sum.
     *
     * Uses Kadane's Algorithm. We maintain a running sum (currentSum) and
     * a global max sum (maxSum). If currentSum becomes negative, we reset
     * it to 0 because a negative sum will only decrease the sum of any
     * subsequent subarray.
     *
     * @param nums Vector of integers.
     * @return int  Maximum subarray sum.
     */
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum < 0) {
                currentSum = 0;
            }
            currentSum += num;
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: standard case with mixed positive and negative numbers
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1 — Max Subarray Sum: " << sol.maxSubArray(nums1) << endl;
    // Expected: 6 (subarray [4, -1, 2, 1])

    // Test 2: single element
    vector<int> nums2 = {1};
    cout << "Test 2 — Max Subarray Sum: " << sol.maxSubArray(nums2) << endl;
    // Expected: 1

    // Test 3: all elements negative
    vector<int> nums3 = {-5, -1, -3};
    cout << "Test 3 — Max Subarray Sum: " << sol.maxSubArray(nums3) << endl;
    // Expected: -1

    return 0;
}
