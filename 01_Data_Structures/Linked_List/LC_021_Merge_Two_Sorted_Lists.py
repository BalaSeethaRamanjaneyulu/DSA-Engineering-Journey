"""
Problem:  Merge Two Sorted Lists
Platform: LeetCode #021
Approach: Iterative with Dummy Node
"""

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Merges two sorted linked lists and returns it as a sorted list.
        
        Args:
            list1 (ListNode): The first sorted list.
            list2 (ListNode): The second sorted list.
            
        Returns:
            ListNode: The merged sorted linked list.
        """
        # dummy node to serve as starting point
        dummy = ListNode(0)
        tail = dummy
        
        # Traverse both lists
        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
            
        # If any elements remain in either list, append them
        tail.next = list1 if list1 else list2
        
        return dummy.next

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def create_linked_list(arr):
    """Auxiliary to create a linked list from a list."""
    if not arr: return None
    dummy = ListNode(0)
    curr = dummy
    for val in arr:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

def print_linked_list(head):
    """Auxiliary to print the linked list in readable format."""
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print(" -> ".join(result) if result else "Empty List")

if __name__ == "__main__":
    sol = Solution()

    # Test Case: [1,2,4] and [1,3,4]
    l1 = create_linked_list([1, 2, 4])
    l2 = create_linked_list([1, 3, 4])

    print("List 1: ", end=""); print_linked_list(l1)
    print("List 2: ", end=""); print_linked_list(l2)

    merged = sol.mergeTwoLists(l1, l2)
    print("Merged: ", end=""); print_linked_list(merged)
