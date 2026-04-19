"""
Problem:  Remove Nth Node From End of List
Platform: LeetCode #019
Approach: Two-Pointer (Gap) Technique with Dummy Node
Efficiency: Time O(N), Space O(1)
"""

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """
        Removes the nth node from the end of the list and returns its head.
        
        Args:
            head (ListNode): The head of the list.
            n (int): The position from the end.
            
        Returns:
            ListNode: The updated head.
        """
        dummy = ListNode(0, head)
        first = dummy
        second = dummy
        
        # Advance 'first' pointer so that there is a gap of n nodes between first and second
        # We move n + 1 steps to position 'second' at the node BEFORE the target.
        for _ in range(n + 1):
            first = first.next
            
        # Move first to the end, maintaining the gap
        while first:
            first = first.next
            second = second.next
            
        # Remove the target node
        second.next = second.next.next
        
        return dummy.next

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def create_list(arr):
    if not arr: return None
    dummy = ListNode(0)
    curr = dummy
    for val in arr:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

def print_list(head):
    res = []
    while head:
        res.append(str(head.val))
        head = head.next
    print(" -> ".join(res) if res else "Empty List")

if __name__ == "__main__":
    sol = Solution()

    # Case: [1, 2, 3, 4, 5], n = 2 -> [1, 2, 3, 5]
    h1 = create_list([1, 2, 3, 4, 5])
    print("Original: ", end=""); print_list(h1)
    h1 = sol.removeNthFromEnd(h1, 2)
    print("Updated:  ", end=""); print_list(h1)
