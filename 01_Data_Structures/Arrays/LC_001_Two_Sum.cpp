/**
 * @file LC_001_Two_Sum.cpp
 * @author Algorithmic Thinking Lab
 * @brief Solution for LeetCode 001: Two Sum
 * @version 0.1
 * @date 2026-02-23
 * 
 * Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * Complexity: Time O(N), Space O(N) where N is the number of elements in the array.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the indices of two numbers that add up to the target.
     * 
     * @param nums Vector of integers.
     * @param target Target sum.
     * @return vector<int> Indices of the two numbers.
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If complement exists in map, we found the pair
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store the current number and its index
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found (though the problem usually guarantees one)
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = sol.twoSum(nums, target);
    
    if (result.size() == 2) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}
