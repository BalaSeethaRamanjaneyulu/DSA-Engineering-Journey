# Problem:  Two Sum
# Platform: LeetCode #1
# Approach: Hash Map (single-pass complement lookup)
# Time:     O(N)  — one pass through the array
# Space:    O(N)  — hash map stores up to N elements
# Link:     https://leetcode.com/problems/two-sum/
#
# Description:
#   Given an array of integers `nums` and an integer `target`, return the
#   indices of the two numbers that add up to target. You may assume that
#   each input has exactly one solution, and you may not use the same
#   element twice.
#
# Key Insight:
#   For each number we check if its complement (target - num) already exists
#   in a hash map. If yes, we found the pair instantly (O(1) lookup).
#   If not, we store the current number and its index for future lookups.
#   This avoids the O(N²) brute-force nested loop.


from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Finds the indices of the two numbers that add up to target.

        Args:
            nums:   List of integers.
            target: Target sum to find.

        Returns:
            List[int]: Indices [i, j] such that nums[i] + nums[j] == target.
        """
        seen = {}  # value -> index

        for i, num in enumerate(nums):
            complement = target - num

            # If complement exists in map, we found the pair
            if complement in seen:
                return [seen[complement], i]

            # Otherwise, store current number and its index
            seen[num] = i

        return []  # No solution found (problem guarantees one exists)


# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1: basic case from LeetCode example
    nums1, target1 = [2, 7, 11, 15], 9
    result1 = sol.twoSum(nums1, target1)
    print(f"Test 1 — Indices: {result1}")
    print(f"         Values:  {nums1[result1[0]]} + {nums1[result1[1]]} = {target1}")
    # Expected: [0, 1]

    # Test 2: target in the middle
    nums2, target2 = [3, 2, 4], 6
    result2 = sol.twoSum(nums2, target2)
    print(f"Test 2 — Indices: {result2}")
    print(f"         Values:  {nums2[result2[0]]} + {nums2[result2[1]]} = {target2}")
    # Expected: [1, 2]

    # Test 3: duplicate values
    nums3, target3 = [3, 3], 6
    result3 = sol.twoSum(nums3, target3)
    print(f"Test 3 — Indices: {result3}")
    print(f"         Values:  {nums3[result3[0]]} + {nums3[result3[1]]} = {target3}")
    # Expected: [0, 1]

    # Test 4: negative numbers
    nums4, target4 = [-1, -2, -3, -4, -5], -8
    result4 = sol.twoSum(nums4, target4)
    print(f"Test 4 — Indices: {result4}")
    print(f"         Values:  {nums4[result4[0]]} + {nums4[result4[1]]} = {target4}")
    # Expected: [2, 4]  →  -3 + -5 = -8
