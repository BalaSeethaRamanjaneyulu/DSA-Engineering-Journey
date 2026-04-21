/**
 * @file LC_025_Reverse_Nodes_in_k_Group.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 025: Reverse Nodes in k-Group
 */

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class LC_025_Reverse_Nodes_in_k_Group {
    /**
     * Reverses the list in groups of k.
     * 
     * @param head The head of the list.
     * @param k The group size.
     * @return ListNode The modified head.
     */
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode curr = head;
        int count = 0;
        
        // Find the k-th node
        while (curr != null && count != k) {
            curr = curr.next;
            count++;
        }
        
        if (count == k) {
            // Reverse the rest of the list recursively
            curr = reverseKGroup(curr, k);
            
            // Reverse the current k nodes
            while (count-- > 0) {
                ListNode nextTemp = head.next;
                head.next = curr;
                curr = head;
                head = nextTemp;
            }
            head = curr;
        }
        return head;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
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
        LC_025_Reverse_Nodes_in_k_Group sol = new LC_025_Reverse_Nodes_in_k_Group();
        ListNode head = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Original: "); printList(head);
        
        head = sol.reverseKGroup(head, 2);
        System.out.print("k=2:      "); printList(head);
    }
}
