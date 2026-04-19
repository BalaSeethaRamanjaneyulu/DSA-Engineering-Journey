"""
Problem:  Linked List Cycle II
Platform: LeetCode #142
Approach: Floyd's Two-Phase Detection
Efficiency: O(N) Time, O(1) Space
"""

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Detects if a cycle exists and returns the entrance node.
        
        Args:
            head (ListNode): The head of the linked list.
            
        Returns:
            ListNode: The entrance node if cycle exists, else None.
        """
        if not head or not head.next:
            return None
            
        slow = head
        fast = head
        
        # Phase 1: Determine meeting point
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            # Intersection point found
            if slow == fast:
                # Phase 2: Identify entrance
                entrance = head
                while entrance != slow:
                    entrance = entrance.next
                    slow = slow.next
                return entrance
                
        return None

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
def create_cycle_list(arr, pos):
    """Auxiliary to create a linked list with a cycle."""
    if not arr: return None
    nodes = [ListNode(x) for x in arr]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    if pos != -1:
        nodes[-1].next = nodes[pos]
    return nodes[0]

if __name__ == "__main__":
    sol = Solution()

    # Case 1: [3, 2, 0, -4], pos = 1
    h1 = create_cycle_list([3, 2, 0, -4], 1)
    res = sol.detectCycle(h1)
    print(f"Test 1 — Entrance Value: {res.val if res else 'None'}")

    # Case 2: [1, 2], pos = 0
    h2 = create_cycle_list([1, 2], 0)
    res = sol.detectCycle(h2)
    print(f"Test 2 — Entrance Value: {res.val if res else 'None'}")
