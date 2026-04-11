/**
 * @file LC_209_Minimum_Size_Subarray_Sum.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 209: Minimum Size Subarray Sum
 *
 * Problem: Given an array of positive integers nums and a positive integer 
 *          target, return the minimal length of a contiguous subarray 
 *          [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater 
 *          than or equal to target. If there is no such subarray, return 0 instead.
 *
 * Platform: LeetCode #209
 * Approach: Sliding Window (Two Pointers)
 * Time:     O(N)  — Each element is visited at most twice by the two pointers
 * Space:    O(1)  — No extra space needed
 * Link:     https://leetcode.com/problems/minimum-size-subarray-sum/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the minimum length of a subarray whose sum is >= target.
     *
     * Uses a sliding window. The 'right' pointer expands the window by adding
     * elements to the running sum. When the sum is >= target, we record the 
     * window's length and shrink it from the left using the 'left' pointer 
     * to find the minimal possible length.
     *
     * @param target The target sum.
     * @param nums Vector of positive integers.
     * @return int Minimal length of the subarray, or 0 if none found.
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_len = INT_MAX;
        
        int left = 0;
        int current_sum = 0;
        
        for (int right = 0; right < n; right++) {
            current_sum += nums[right];
            
            // Shrink the window as long as the condition is met
            while (current_sum >= target) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        
        return min_len == INT_MAX ? 0 : min_len;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Test 1 — Minimal Length: " << sol.minSubArrayLen(target1, nums1) << endl;
    // Expected: 2 (subarray [4, 3])

    // Test 2: Exact match
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    cout << "Test 2 — Minimal Length: " << sol.minSubArrayLen(target2, nums2) << endl;
    // Expected: 1 (subarray [4])

    // Test 3: No valid subarray
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    cout << "Test 3 — Minimal Length: " << sol.minSubArrayLen(target3, nums3) << endl;
    // Expected: 0

    return 0;
}
