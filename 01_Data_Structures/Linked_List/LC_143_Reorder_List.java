/**
 * @file LC_143_Reorder_List.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 143: Reorder List
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

public class LC_143_Reorder_List {
    /**
     * Reorders the list in-place by finding the middle, reversing the second half,
     * and merging the two halves alternatingly.
     * 
     * @param head The head of the linked list.
     */
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return;
        }

        // 1. Find Middle (Slow and Fast Pointers)
        ListNode slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2. Reverse Second Half
        ListNode curr = slow.next;
        slow.next = null; // Split lists
        ListNode prev = null;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // 3. Merge Halves Alternatingly
        ListNode first = head;
        ListNode second = prev;
        while (second != null) {
            ListNode tmp1 = first.next;
            ListNode tmp2 = second.next;

            first.next = second;
            second.next = tmp1;

            first = tmp1;
            second = tmp2;
        }
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
        LC_143_Reorder_List sol = new LC_143_Reorder_List();

        // [1,2,3,4,5] -> [1,5,2,4,3]
        ListNode head = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Original: "); printList(head);

        sol.reorderList(head);
        System.out.print("Reordered: "); printList(head);
    }
}
