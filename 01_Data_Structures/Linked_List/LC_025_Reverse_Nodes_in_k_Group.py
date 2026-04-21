"""
Problem:  Reverse Nodes in k-Group
Platform: LeetCode #025 (Hard)
Approach: Recursive Group Reversal
Efficiency: Time O(N), Space O(N/k) stack
"""

from typing import Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        Reverses nodes of the list k at a time.
        """
        curr = head
        count = 0
        
        # 1. Find if there are at least k nodes available
        while curr and count != k:
            curr = curr.next
            count += 1
            
        if count == k:
            # 2. Reverse sub-list from (k+1)-th node
            curr = self.reverseKGroup(curr, k)
            
            # 3. Reverse current k nodes
            # curr acts as the 'prev' for the segment reversal
            while count > 0:
                next_temp = head.next
                head.next = curr
                curr = head
                head = next_temp
                count -= 1
            head = curr
            
        return head

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

    # Case: [1, 2, 3, 4, 5], k = 2 -> [2, 1, 4, 3, 5]
    h1 = create_list([1, 2, 3, 4, 5])
    print("Original: ", end=""); print_list(h1)
    result = sol.reverseKGroup(h1, 2)
    print("k=2:      ", end=""); print_list(result)

    # Case: [1, 2, 3, 4, 5], k = 3 -> [3, 2, 1, 4, 5]
    h2 = create_list([1, 2, 3, 4, 5])
    result2 = sol.reverseKGroup(h2, 3)
    print("k=3:      ", end=""); print_list(result2)
