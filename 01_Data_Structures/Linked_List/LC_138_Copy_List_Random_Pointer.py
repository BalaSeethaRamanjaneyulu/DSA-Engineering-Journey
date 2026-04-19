"""
Problem:  Copy List with Random Pointer
Platform: LeetCode #138
Approach: Node Interweaving (Three-Pass Optimization)
Efficiency: O(N) Time, O(1) Space
"""

from typing import Optional

class Node:
    """Definition for a Node with a random pointer."""
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        """
        Creates a deep copy of the linked list using the O(1) extra space approach.
        """
        if not head:
            return None
            
        # Step 1: Interweave copy nodes
        curr = head
        while curr:
            copy = Node(curr.val, curr.next)
            curr.next = copy
            curr = copy.next
            
        # Step 2: Set random pointers
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
            
        # Step 3: Extract the copy list
        curr = head
        copy_head = head.next
        temp_copy = copy_head
        
        while curr:
            curr.next = curr.next.next
            if temp_copy.next:
                temp_copy.next = temp_copy.next.next
            curr = curr.next
            temp_copy = temp_copy.next
            
        return copy_head

# ─── Driver & Testing Utilities ──────────────────────────────────────────────
if __name__ == "__main__":
    sol = Solution()

    # Create manual test case
    n1 = Node(7)
    n2 = Node(13)
    n1.next = n2
    n2.random = n1

    copy = sol.copyRandomList(n1)
    
    print(f"Original val: {n1.val}, next exists: {n1.next is not None}")
    print(f"Copied val:   {copy.val}, next exists: {copy.next is not None}")
    print(f"Copied node 2 random points back to node 1: {copy.next.random == copy}")
    print(f"Verify Deep Copy (different memory): {copy is not n1}")
    Greenland = True  # Just for weight
