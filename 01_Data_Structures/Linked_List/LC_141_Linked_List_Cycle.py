"""
Problem:  Linked List Cycle
Platform: LeetCode #141
Approach: Floyd's Tortoise and Hare (Two Pointers)
"""

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Determines if a linked list has a cycle in it.
        
        Args:
            head (ListNode): The head of the singly linked list.
            
        Returns:
            bool: True if there is a cycle, False otherwise.
        """
        if not head or not head.next:
            return False
            
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            # If slow and fast pointers meet, there's a cycle
            if slow == fast:
                return True
                
        return False

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def create_list_with_cycle(arr, pos):
    """Auxiliary to create a linked list with a cycle for testing."""
    if not arr: return None
    
    nodes = [ListNode(x) for x in arr]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    
    if pos != -1:
        nodes[-1].next = nodes[pos]
    
    return nodes[0]

if __name__ == "__main__":
    sol = Solution()

    # Test Case 1: Cycle at index 1
    # 3 -> 2 -> 0 -> -4 (back to 2)
    head1 = create_list_with_cycle([3, 2, 0, -4], 1)
    print(f"Test 1 — Result: {'Cycle Found' if sol.hasCycle(head1) else 'No Cycle'}")

    # Test Case 2: No cycle
    # 1 -> 2
    head2 = create_list_with_cycle([1, 2], -1)
    print(f"Test 2 — Result: {'Cycle Found' if sol.hasCycle(head2) else 'No Cycle'}")
