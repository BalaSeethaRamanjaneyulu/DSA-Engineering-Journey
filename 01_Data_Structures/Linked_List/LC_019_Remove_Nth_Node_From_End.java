/**
 * @file LC_019_Remove_Nth_Node_From_End.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 019: Remove Nth Node From End of List
 */

/**
 * Definition for singly-linked list node.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class LC_019_Remove_Nth_Node_From_End {
    /**
     * Removes the N-th node from the end by maintaining a window/gap of size N
     * between two pointers.
     * 
     * @param head The head of the list.
     * @param n The position from the end.
     * @return ListNode The updated head.
     */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;

        // Gap the pointers
        for (int i = 0; i <= n; i++) {
            first = first.next;
        }

        // Move the window to the end
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        // Delete the node
        second.next = second.next.next;

        return dummy.next;
    }

    // ─── Driver & Utilities ──────────────────────────────────────────────────
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " -> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    public static ListNode createList(int[] nums) {
        if (nums.length == 0) return null;
        ListNode head = new ListNode(nums[0]);
        ListNode curr = head;
        for (int i = 1; i < nums.length; i++) {
            curr.next = new ListNode(nums[i]);
            curr = curr.next;
        }
        return head;
    }

    public static void main(String[] args) {
        LC_019_Remove_Nth_Node_From_End sol = new LC_019_Remove_Nth_Node_From_End();

        // [1,2,3,4,5], n = 2 -> [1,2,3,5]
        ListNode head = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Original: "); printList(head);

        head = sol.removeNthFromEnd(head, 2);
        System.out.print("Updated:  "); printList(head);
    }
}
