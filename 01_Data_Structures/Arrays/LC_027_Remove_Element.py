# Problem:  Remove Element
# Platform: LeetCode #27
# Approach: Two Pointers (write-pointer / slow-fast pointer)
# Time:     O(N)  — single pass through the array
# Space:    O(1)  — in-place modification, no extra storage
# Link:     https://leetcode.com/problems/remove-element/
#
# Description:
#   Given a list `nums` and an integer `val`, erase all occurrences of
#   `val` in-place. The relative order of the remaining elements may change.
#   Return k — the count of elements that are NOT equal to val.
#
# Key Insight:
#   A "write pointer" k only advances when the current element is valid
#   (not equal to val). Elements equal to val are simply skipped, so they
#   are effectively erased without extra memory.


from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        """
        Erases all occurrences of `val` from `nums` in-place.

        Args:
            nums: The list of integers to modify in-place.
            val:  The target value to erase / remove.

        Returns:
            k: The number of elements remaining (not equal to val).
               The first k elements of nums hold the valid result.
        """
        k = 0  # write pointer — next position for a valid element

        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]  # copy valid element to the write slot
                k += 1
            # nums[i] == val → skip / erase by NOT moving k forward

        return k  # nums[:k] contains the answer


# ─── Driver ──────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Test 1: standard erase
    nums1 = [3, 2, 2, 3]
    k1 = sol.removeElement(nums1, 3)
    print(f"Test 1 — k = {k1}, result: {nums1[:k1]}")
    # Expected: k=2, result=[2, 2]

    # Test 2: typical mixed array
    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    k2 = sol.removeElement(nums2, 2)
    print(f"Test 2 — k = {k2}, result: {nums2[:k2]}")
    # Expected: k=5, result=[0, 1, 3, 0, 4]

    # Test 3: all elements equal val (nothing survives)
    nums3 = [7, 7, 7]
    k3 = sol.removeElement(nums3, 7)
    print(f"Test 3 — k = {k3} (expected 0)")

    # Test 4: val not present (nothing erased, all survive)
    nums4 = [1, 2, 3]
    k4 = sol.removeElement(nums4, 9)
    print(f"Test 4 — k = {k4} (expected 3)")
