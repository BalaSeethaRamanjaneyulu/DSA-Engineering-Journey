/**
 * @file LC_141_Linked_List_Cycle.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 141: Linked List Cycle
 */

/**
 * Definition for singly-linked list node.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class LC_141_Linked_List_Cycle {
    /**
     * Determines if a linked list has a cycle using Floyd's Tortoise and Hare algorithm.
     * 
     * @param head The head of the list.
     * @return boolean True if cycle exists, else false.
     */
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            // Cycle detected
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_141_Linked_List_Cycle sol = new LC_141_Linked_List_Cycle();

        // Test 1: Cycle
        ListNode head1 = new ListNode(3);
        ListNode node2 = new ListNode(2);
        head1.next = node2;
        node2.next = new ListNode(0);
        node2.next.next = new ListNode(-4);
        node2.next.next.next = node2; // cycle

        System.out.println("Test 1 — Result: " + (sol.hasCycle(head1) ? "Cycle Found" : "No Cycle"));

        // Test 2: No Cycle
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        System.out.println("Test 2 — Result: " + (sol.hasCycle(head2) ? "Cycle Found" : "No Cycle"));
    }
}
