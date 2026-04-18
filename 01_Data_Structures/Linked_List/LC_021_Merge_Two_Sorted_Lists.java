/**
 * @file LC_021_Merge_Two_Sorted_Lists.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 021: Merge Two Sorted Lists
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

public class LC_021_Merge_Two_Sorted_Lists {
    /**
     * Merges two sorted linked lists using a dummy node.
     *
     * @param list1 The first sorted list.
     * @param list2 The second sorted list.
     * @return ListNode The head of the merged list.
     */
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }

        // Attach remaining nodes
        tail.next = (list1 != null) ? list1 : list2;

        return dummy.next;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " -> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LC_021_Merge_Two_Sorted_Lists sol = new LC_021_Merge_Two_Sorted_Lists();

        ListNode l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

        System.out.print("List 1: "); printList(l1);
        System.out.print("List 2: "); printList(l2);

        ListNode merged = sol.mergeTwoLists(l1, l2);
        System.out.print("Merged: "); printList(merged);
    }
}
