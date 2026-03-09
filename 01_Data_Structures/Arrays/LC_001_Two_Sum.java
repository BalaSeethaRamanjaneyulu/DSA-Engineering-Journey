
/**
 * @file LC_001_Two_Sum.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 001: Two Sum
 * 
 * Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * Complexity: Time O(N), Space O(N)
 */

import java.util.HashMap;
import java.util.Map;

public class LC_001_Two_Sum {

    /**
     * Finds the indices of two numbers that add up to the target.
     * 
     * @param nums   Array of integers.
     * @param target Target sum.
     * @return int[] Indices of the two numbers.
     */
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>(); // value -> index

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            // If complement exists in map, we found the pair
            if (numMap.containsKey(complement)) {
                return new int[] { numMap.get(complement), i };
            }

            // Otherwise, store current number and its index
            numMap.put(nums[i], i);
        }

        return new int[] {}; // No solution found
    }

    public static void main(String[] args) {
        LC_001_Two_Sum sol = new LC_001_Two_Sum();
        int[] nums = { 2, 7, 11, 15 };
        int target = 9;

        int[] result = sol.twoSum(nums, target);

        if (result.length == 2) {
            System.out.println("Indices: [" + result[0] + ", " + result[1] + "]");
            System.out.println("Values: " + nums[result[0]] + " + " + nums[result[1]] + " = " + target);
        } else {
            System.out.println("No solution found.");
        }
    }
}
