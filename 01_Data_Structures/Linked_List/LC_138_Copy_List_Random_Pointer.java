/**
 * @file LC_138_Copy_List_Random_Pointer.java
 * @author BalaSeethaRamanjaneyulu
 * @brief Java Solution for LeetCode 138: Copy List with Random Pointer
 */

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

public class LC_138_Copy_List_Random_Pointer {
    /**
     * Creates a deep copy of the list using the interweaving nodes approach.
     * 
     * @param head The head of the original list.
     * @return Node The head of the deep-copied list.
     */
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        // Step 1: Interweave copy nodes
        Node curr = head;
        while (curr != null) {
            Node copy = new Node(curr.val);
            copy.next = curr.next;
            curr.next = copy;
            curr = copy.next;
        }

        // Step 2: Set random pointers for copy nodes
        curr = head;
        while (curr != null) {
            if (curr.random != null) {
                curr.next.random = curr.random.next;
            }
            curr = curr.next.next;
        }

        // Step 3: Extract the copy list
        curr = head;
        Node copyHead = head.next;
        Node tempCopy = copyHead;

        while (curr != null) {
            curr.next = curr.next.next;
            if (tempCopy.next != null) {
                tempCopy.next = tempCopy.next.next;
            }
            curr = curr.next;
            tempCopy = tempCopy.next;
        }

        return copyHead;
    }

    // ─── Driver ──────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        LC_138_Copy_List_Random_Pointer sol = new LC_138_Copy_List_Random_Pointer();

        Node n1 = new Node(1);
        Node n2 = new Node(2);
        n1.next = n2;
        n1.random = n2;
        n2.random = n2;

        Node copy = sol.copyRandomList(n1);
        System.out.println("Original node 1 val: " + n1.val);
        System.out.println("Copied node 1 val:   " + copy.val);
        System.out.println("Copied node 1 random points to: " + copy.random.val);
    }
}
