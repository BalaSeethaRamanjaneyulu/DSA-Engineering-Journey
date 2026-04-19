/**
 * @file LC_019_Remove_Nth_Node_From_End.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 019: Remove Nth Node From End of List
 *
 * Problem: Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Platform: LeetCode #019
 * Approach: One-Pass Two-Pointer (Gap) Technique with Dummy Node
 * Time:     O(N)
 * Space:    O(1)
 * Link:     https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * @brief Removes the Nth node from the end in a single pass.
     * 
     * We maintain two pointers, 'first' and 'second', with a gap of N nodes.
     * When 'first' reaches the end, 'second' will be at the node before the target.
     * 
     * @param head The head of the list.
     * @param n The index from the end.
     * @return ListNode* The updated head.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        // Advance 'first' pointer so that the gap between 'first' and 'second' is n nodes
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // Move 'first' to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Skip the Nth node from the end
        ListNode* to_delete = second->next;
        second->next = second->next->next;
        delete to_delete; // Clean up memory
        
        return dummy.next;
    }
};

// ─── Driver & Utilities ──────────────────────────────────────────────────────
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test Case: [1,2,3,4,5], n = 2 -> [1,2,3,5]
    ListNode* head = createList({1, 2, 3, 4, 5});
    cout << "Original: "; printList(head);

    head = sol.removeNthFromEnd(head, 2);
    cout << "After removing 2nd from end: "; printList(head);

    return 0;
}
