/**
 * @file LC_141_Linked_List_Cycle.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 141: Linked List Cycle
 *
 * Problem: Given head, the head of a linked list, determine if the linked list has a cycle in it.
 *
 * Platform: LeetCode #141
 * Approach: Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
 * Time:     O(N)
 * Space:    O(1)
 * Link:     https://leetcode.com/problems/linked-list-cycle/
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * @brief Determines if a linked list has a cycle iteratively.
     *
     * We use two pointers, slow and fast:
     * - slow moves one step at a time.
     * - fast moves two steps at a time.
     * If they meet, there is a cycle.
     *
     * @param head Pointer to the head of the list.
     * @return bool True if there is a cycle, false otherwise.
     */
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        
        return false;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test Case 1: Cycle exists
    ListNode *head1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Cycle back to node2

    cout << "Test 1 — Result: " << (sol.hasCycle(head1) ? "Cycle Found" : "No Cycle") << endl;

    // Test Case 2: No cycle
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    cout << "Test 2 — Result: " << (sol.hasCycle(head2) ? "Cycle Found" : "No Cycle") << endl;

    return 0;
}
