# Problem:  Reverse Linked List
# Platform: LeetCode #206
# Approach: Iterative (Three Pointers)
# Time:     O(N)  — Single pass.
# Space:    O(1)  — In-place.
# Link:     https://leetcode.com/problems/reverse-linked-list/
#
# Description:
#   Given the head of a singly linked list, reverse the list, 
#   and return the reversed list.

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Reverses a singly linked list iteratively.
        
        Args:
            head: Pointer to the head of the list.
            
        Returns:
            ListNode: Pointer to the new head.
        """
        prev = None
        curr = head
        
        while curr:
            next_temp = curr.next # Temporarily store next
            curr.next = prev      # Reverse direction
            prev = curr           # Shift prev forward
            curr = next_temp      # Shift curr forward
            
        return prev

# ─── Driver ──────────────────────────────────────────────────────────────────
def print_list(node: Optional[ListNode]):
    elements = []
    while node:
        elements.append(str(node.val))
        node = node.next
    print(" -> ".join(elements))

if __name__ == "__main__":
    sol = Solution()

    # 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

    print("Original List: ", end="")
    print_list(head)

    reversed_head = sol.reverseList(head)

    print("Reversed List: ", end="")
    print_list(reversed_head)
