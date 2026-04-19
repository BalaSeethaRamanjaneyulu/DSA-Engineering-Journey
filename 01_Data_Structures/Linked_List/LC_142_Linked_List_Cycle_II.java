/**
 * @file LC_142_Linked_List_Cycle_II.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 142: Linked List Cycle II
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

public class LC_142_Linked_List_Cycle_II {
    /**
     * Detects the cycle entrance node using Floyd's two-pointer algorithm.
     * 
     * @param head Head of the linked list.
     * @return ListNode The node where the cycle begins, or null.
     */
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        // Phase 1: Finding meeting point
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                // Phase 2: Finding entrance
                ListNode entry = head;
                while (entry != slow) {
                    entry = entry.next;
                    slow = slow.next;
                }
                return entry;
            }
        }

        return null;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_142_Linked_List_Cycle_II sol = new LC_142_Linked_List_Cycle_II();

        // [3,2,0,-4], pos = 1 (cycle back to 2)
        ListNode head = new ListNode(3);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(0);
        ListNode node4 = new ListNode(-4);
        head.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2;

        ListNode entrance = sol.detectCycle(head);
        if (entrance != null) {
            System.out.println("Cycle entrance found at node with value: " + entrance.val);
        } else {
            System.out.println("No cycle found");
        }
    }
}
