/**
 * @file LC_206_Reverse_Linked_List.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 206: Reverse Linked List
 *
 * Problem: Given the head of a singly linked list, reverse the list, 
 *          and return the reversed list.
 *
 * Platform: LeetCode #206
 * Approach: Iterative (Three Pointers)
 * Time:     O(N)  — Single pass through the list.
 * Space:    O(1)  — In-place reversal using three pointers.
 * Link:     https://leetcode.com/problems/reverse-linked-list/
 */

public class LC_206_Reverse_Linked_List {

    /**
     * Definition for singly-linked list node.
     */
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Reverses a singly linked list iteratively.
     *
     * @param head Pointer to the head of the list.
     * @return ListNode Pointer to the new head of the reversed list.
     */
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        
        while (curr != null) {
            ListNode nextTemp = curr.next; // Store next node
            curr.next = prev;            // Reverse direction
            prev = curr;                 // Shift prev
            curr = nextTemp;             // Shift curr
        }
        
        return prev; // prev will be at the new head
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + (node.next != null ? " -> " : ""));
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LC_206_Reverse_Linked_List sol = new LC_206_Reverse_Linked_List();

        // 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

        System.out.print("Original List: ");
        printList(head);

        ListNode reversed = sol.reverseList(head);

        System.out.print("Reversed List: ");
        printList(reversed);
    }
}
