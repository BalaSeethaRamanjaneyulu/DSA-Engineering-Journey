/**
 * @file LC_238_Product_of_Array_Except_Self.java
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

import java.util.Arrays;

public class LC_238_Product_of_Array_Except_Self {

    /**
     * Computes the product of array except self without division.
     *
     * @param nums Array of integers.
     * @return int[] Product array result.
     */
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        
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

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_238_Product_of_Array_Except_Self sol = new LC_238_Product_of_Array_Except_Self();

        // Test 1
        int[] nums1 = {1, 2, 3, 4};
        System.out.println("Test 1 — Result: " + Arrays.toString(sol.productExceptSelf(nums1)));
        // Expected: [24, 12, 8, 6]

        // Test 2
        int[] nums2 = {-1, 1, 0, -3, 3};
        System.out.println("Test 2 — Result: " + Arrays.toString(sol.productExceptSelf(nums2)));
        // Expected: [0, 0, 9, 0, 0]
    }
}
