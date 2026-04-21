/**
 * @file LC_023_Merge_k_Sorted_Lists.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 023: Merge k Sorted Lists
 */

import java.util.PriorityQueue;

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

public class LC_023_Merge_k_Sorted_Lists {
    /**
     * Merges k sorted lists using a PriorityQueue (Min-Heap).
     * 1. Add the head of every list to the heap.
     * 2. Repeatedly extract the minimum node and add its 'next' pointer to the heap.
     * 
     * @param lists Array of linked-list heads.
     * @return ListNode The merged sorted list head.
     */
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;

        // Min-heap sorted by node value
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Add initial heads
        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!pq.isEmpty()) {
            ListNode minNode = pq.poll();
            tail.next = minNode;
            tail = tail.next;

            if (minNode.next != null) {
                pq.add(minNode.next);
            }
        }

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
        LC_023_Merge_k_Sorted_Lists sol = new LC_023_Merge_k_Sorted_Lists();

        ListNode[] lists = new ListNode[3];
        lists[0] = createList(new int[]{1, 4, 5});
        lists[1] = createList(new int[]{1, 3, 4});
        lists[2] = createList(new int[]{2, 6});

        ListNode merged = sol.mergeKLists(lists);
        System.out.print("Merged List: "); printList(merged);
    }
}
