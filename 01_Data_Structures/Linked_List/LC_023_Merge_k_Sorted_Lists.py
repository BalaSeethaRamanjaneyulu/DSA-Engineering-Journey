"""
Problem:  Merge k Sorted Lists
Platform: LeetCode #023
Approach: Min-Heap using heapq
Efficiency: O(N log k) Time, O(k) Space
"""

import heapq
from typing import List, Optional

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    # Required for heapq in cases where values are identical
    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        Merges k sorted lists using a Min-Heap.
        """
        min_heap = []
        
        # 1. Add the initial head of each list to the heap
        for head in lists:
            if head:
                heapq.heappush(min_heap, (head.val, head))
                
        dummy = ListNode(0)
        tail = dummy
        
        # 2. Process the heap
        while min_heap:
            val, node = heapq.heappop(min_heap)
            tail.next = node
            tail = tail.next
            
            if node.next:
                heapq.heappush(min_heap, (node.next.val, node.next))
                
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

    # Case: [[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]
    l1 = create_list([1, 4, 5])
    l2 = create_list([1, 3, 4])
    l3 = create_list([2, 6])

    print("Input Lists:")
    print_list(l1); print_list(l2); print_list(l3)

    result = sol.mergeKLists([l1, l2, l3])
    print("Merged Result:", end=" ")
    print_list(result)
