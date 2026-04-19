/**
 * @file LC_143_Reorder_List.cpp
 * @author BalaSeethaRamanjaneyulu
 * @brief Solution for LeetCode 143: Reorder List
 *
 * Problem: Given head of a singly linked list [L0->L1->...->Ln-1->Ln],
 * reorder it to: [L0->Ln->L1->Ln-1->L2->Ln-2->...]
 *
 * Platform: LeetCode #143
 * Approach: Find Middle -> Reverse Second Half -> Merge Alternatingly
 * Time:     O(N)
 * Space:    O(1)
 * Link:     https://leetcode.com/problems/reorder-list/
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
     * @brief Reorders the list in-place using the three-step pattern.
     * 1. Find the middle of the list.
     * 2. Reverse the second half of the list.
     * 3. Merge the two halves alternatingly.
     * 
     * @param head The head of the linked list.
     */
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        
        // 1. Find Middle (Slow and Fast Pointers)
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse Second Half
        ListNode *curr = slow->next;
        slow->next = nullptr; // Split lists
        ListNode *prev = nullptr;
        while (curr) {
            ListNode *next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        
        // 3. Merge Halves Alternatingly
        ListNode *first = head;
        ListNode *second = prev; // Head of reversed second half
        while (second) {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;
            
            first->next = second;
            second->next = tmp1;
            
            first = tmp1;
            second = tmp2;
        }
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

    // Test Case: [1,2,3,4,5] -> [1,5,2,4,3]
    ListNode* head = createList({1, 2, 3, 4, 5});
    cout << "Original: "; printList(head);

    sol.reorderList(head);
    cout << "Reordered: "; printList(head);

    return 0;
}
