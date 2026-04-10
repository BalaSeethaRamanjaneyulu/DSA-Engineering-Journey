/**
 * @file LC_238_Product_of_Array_Except_Self.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 238: Product of Array Except Self
 *
 * Problem: Given an integer array nums, return an array answer such that 
 *          answer[i] is equal to the product of all the elements of nums 
 *          except nums[i]. You must write an algorithm that runs in O(n) 
 *          time and without using the division operation.
 *
 * Platform: LeetCode #238
 * Approach: Prefix and Suffix Products (Left & Right Passes)
 * Time:     O(N)  — two passes over the array
 * Space:    O(1)  — excluding the output array, all computations in-place
 * Link:     https://leetcode.com/problems/product-of-array-except-self/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Computes the product of array except self without division.
     *
     * We calculate the prefix product of all elements to the left of 'i' 
     * and store it in the result array. Then, we do a right-to-left sweep 
     * maintaining a running suffix product and multiplying it with the left 
     * product already in the result array.
     *
     * @param nums Vector of integers.
     * @return vector<int> Product array result.
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Pass 1: Compute left prefix products
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        // Pass 2: Compute right suffix products and multiply with left product
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> res1 = sol.productExceptSelf(nums1);
    cout << "Test 1 — Result: [";
    for (int i = 0; i < res1.size(); i++) cout << res1[i] << (i < res1.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [24, 12, 8, 6]

    // Test 2: Contains zero
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> res2 = sol.productExceptSelf(nums2);
    cout << "Test 2 — Result: [";
    for (int i = 0; i < res2.size(); i++) cout << res2[i] << (i < res2.size() - 1 ? ", " : "");
    cout << "]" << endl;
    // Expected: [0, 0, 9, 0, 0]

    return 0;
}
