"""
Problem:  Reorder List
Platform: LeetCode #143
Approach: Middle + Reverse + Alternating Merge
Efficiency: Time O(N), Space O(1)
"""

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return

        # 1. Find the middle
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # 2. Reverse the second half
        curr = slow.next
        slow.next = None  # break the link
        prev = None
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
        
        # 3. Merge alternatingly
        first, second = head, prev
        while second:
            tmp1, tmp2 = first.next, second.next
            
            first.next = second
            second.next = tmp1
            
            first, second = tmp1, tmp2

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def create_list(arr):
    if not arr: return None
    head = ListNode(arr[0])
    curr = head
    for i in range(1, len(arr)):
        curr.next = ListNode(arr[i])
        curr = curr.next
    return head

def print_list(head):
    res = []
    while head:
        res.append(str(head.val))
        head = head.next
    print(" -> ".join(res))

if __name__ == "__main__":
    sol = Solution()

    # Case 1: [1, 2, 3, 4, 5] -> [1, 5, 2, 4, 3]
    h1 = create_list([1, 2, 3, 4, 5])
    print("Original: ", end=""); print_list(h1)
    sol.reorderList(h1)
    print("Reordered:", end=""); print_list(h1)
