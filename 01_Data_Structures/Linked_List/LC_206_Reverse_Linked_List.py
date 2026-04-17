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
        Reverses a singly linked list iteratively using the Three-Pointer technique.
        
        The algorithm works by traversing the list once and re-orienting each node's 
        'next' pointer to its previous node. This achieves an in-place reversal 
        without extra memory.
        
        Args:
            head (Optional[ListNode]): The current head node of the linked list.
            
        Returns:
            Optional[ListNode]: The new head node of the reversed linked list.
            
        Complexity Analysis:
            Time: O(N) — We visit each node exactly once.
            Space: O(1) — We only use three auxiliary pointers regardless of N.
        """
        # Pointer initialization
        # prev: will eventually become the new head of the reversed list.
        # curr: the node we are currently processing.
        prev = None
        curr = head
        
        while curr:
            # 1. Preservation: Store the next node before we overwrite curr.next.
            next_temp = curr.next 
            
            # 2. Reversal: Point the current node back to the previous node.
            curr.next = prev      
            
            # 3. Transition: Move prev and curr one step forward for the next iteration.
            prev = curr           
            curr = next_temp      
            
        # At the end of the loop, curr is None and prev is the last valid node (new head).
        return prev

# ─── Logic Visualization ─────────────────────────────────────────────────────
#
# Initial:  [1] -> [2] -> [3] -> None
#           (h)
#
# Iteration 1:
#   next_temp = [2]
#   curr.next = None (points back to prev)
#   prev = [1]
#   curr = [2]
#   State:  None <- [1]  [2] -> [3] -> None
#                   (p)  (c)
#
# Iteration 2:
#   next_temp = [3]
#   curr.next = [1]
#   prev = [2]
#   curr = [3]
#   State:  None <- [1] <- [2]  [3] -> None
#                          (p)  (c)
#
# Iteration 3:
#   next_temp = None
#   curr.next = [2]
#   prev = [3]
#   curr = None
#   State:  None <- [1] <- [2] <- [3] (New Head)
#                                 (p)
# ─────────────────────────────────────────────────────────────────────────────

# ─── Driver ──────────────────────────────────────────────────────────────────
def print_list(node: Optional[ListNode]):
    """Helper to visualize the list in the console."""
    elements = []
    temp = node
    while temp:
        elements.append(str(temp.val))
        temp = temp.next
    print(" -> ".join(elements) if elements else "Empty List")

if __name__ == "__main__":
    sol = Solution()

    # Create List: 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

    print("Original List: ", end="")
    print_list(head)

    reversed_head = sol.reverseList(head)

    print("Reversed List: ", end="")
    print_list(reversed_head)
