/**
 * @file LC_142_Linked_List_Cycle_II.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 142: Linked List Cycle II
 *
 * Problem: Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Platform: LeetCode #142
 * Approach: Floyd's Phase 2 (Cycle Entrance Detection)
 * Time:     O(N)
 * Space:    O(1)
 * Link:     https://leetcode.com/problems/linked-list-cycle-ii/
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
     * @brief Finds the entry node of the cycle using Floyd's two-phase approach.
     * 
     * Phase 1: Determine if a cycle exists and find the meeting point.
     * Phase 2: Find the entrance by moving 'head' and 'slow' at the same speed.
     * 
     * @param head Head of the linked list.
     * @return ListNode* The node where the cycle begins, or nullptr.
     */
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Phase 1: Detect Cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Phase 2: Find Entrance
                ListNode *entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        
        return nullptr;
    }
};

// ─── Driver ──────────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test Case: 3 -> 2 -> 0 -> -4 (cycle back to 2)
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; 

    ListNode *entrance = sol.detectCycle(head);
    if (entrance) {
        cout << "Cycle entrance found at node with value: " << entrance->val << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    return 0;
}
